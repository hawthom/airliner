/*
** File: osapi-os-net.h
**
**      Copyright (c) 2004-2006, United States government as represented by the 
**      administrator of the National Aeronautics Space Administration.  
**      All rights reserved. This software was created at NASAs Goddard 
**      Space Flight Center pursuant to government contracts.
**
**      This is governed by the NASA Open Source Agreement and may be used, 
**      distributed and modified only pursuant to the terms of that agreement.
**
** Author:  Alan Cudmore Code 582
**
** Purpose: Contains functions prototype definitions and variables declarations
**          for the OS Abstraction Layer, Network Module
**
*/
#ifndef _osapi_network_
#define _osapi_network_

/* NOTE - osconfig.h may optionally specify the value for OS_SOCADDR_MAX_LEN */
#include <osconfig.h>

/*
 * The absolute maximum size of a network address
 *
 * The actual size varies by address type.
 *
 * This definition should be large enough to capture the
 * largest address supported on the system.  The default
 * value here should be suitable for many use-cases while
 * still keeping the address structure size within reason.
 *
 * The user may also provide a tuned value through osconfig.h
 */
#ifndef OS_SOCKADDR_MAX_LEN
#define OS_SOCKADDR_MAX_LEN     28
#endif


/*
 * --------------------------------------------------------------------------------------
 * Sockets API Data Types
 *
 * These data types are defined regardless of whether or not networking is compiled-in
 *
 * They are local to OSAL, they do not directly map to the library-provided types, and
 * they do not occupy any space in the executable
 * --------------------------------------------------------------------------------------
 */

typedef enum
{
   OS_SocketDomain_INVALID,
   OS_SocketDomain_INET,        /**< IPv4 address family, most commonly used) */
   OS_SocketDomain_INET6,       /**< IPv6 address family, depends on OS/network stack support */
   OS_SocketDomain_MAX
} OS_SocketDomain_t;

typedef enum
{
   OS_SocketType_INVALID,
   OS_SocketType_DATAGRAM,      /**< A connectionless, message-oriented socket */
   OS_SocketType_STREAM,        /**< A stream-oriented socket with the concept of a connection */
   OS_SocketType_MAX
} OS_SocketType_t;


/**
 * Encapsulates a generic network address
 *
 * This is just an abstract buffer type that holds a network address.
 * It is allocated for the worst-case size defined by OS_SOCKADDR_MAX_LEN,
 * and the real size is stored within.
 */
typedef struct
{
   uint32 ActualLength;                 /**< Length of the actual address data */
   char AddrData[OS_SOCKADDR_MAX_LEN];  /**< Abstract Address data */
} OS_SockAddr_t;

/**
 * Encapsulates socket properties
 *
 * This is for consistency with other OSAL resource types.
 * Currently no extra properties are exposed here but this
 * could change in a future revision of OSAL as needed.
 */
typedef struct
{
    char name [OS_MAX_API_NAME];        /**< Name of the socket */
    uint32 creator;                     /**< OSAL TaskID which opened the socket */
} OS_socket_prop_t;




/*
 * --------------------------------------------------------------------------------------
 * Socket Address API Functions
 *
 * These functions provide a means to manipulate network addresses in a manner that
 * is (mostly) agnostic to the actual network address type.
 *
 * Every network address should be representable as a string (i.e. dotted decimal IP, etc).
 * This can serve as a the "common denominator" to all address types.
 * --------------------------------------------------------------------------------------
 */

/**
 * Initialize a socket address structure to hold an address of the given family
 *
 * The address is set to a suitable default value for the family.
 *
 * @param  Addr         The address buffer to initialize
 * @param  Domain       The address family
 * @returns OS_SUCCESS if successful
 */
int32 OS_SocketAddrInit(OS_SockAddr_t *Addr, OS_SocketDomain_t Domain);

/**
 * Get a string representation of a network host address
 *
 * The specific format of the output string depends on the address family.
 *
 * This string should be suitable to pass back into OS_SocketAddrFromString()
 * which should recreate the same network address, and it should also
 * be meaningful to a user of printed or logged as a C string.
 *
 * @note For IPv4, this would typically be the dotted-decimal format (X.X.X.X).
 *
 * @param  buffer       Buffer to hold the output string
 * @param  buflen       Maximum length of the output string
 * @param  Addr         The network address buffer to convert
 * @returns OS_SUCCESS if successful
 */
int32 OS_SocketAddrToString(char *buffer, uint32 buflen, const OS_SockAddr_t *Addr);

/**
 * Set a network host address from a string representation
 *
 * The specific format of the output string depends on the address family.
 *
 * The address structure should have been previously initialized using
 * OS_SocketAddrInit() to set the address family type.
 *
 * @note For IPv4, this would typically be the dotted-decimal format (X.X.X.X).
 * It is up to the discretion of the underlying implementation whether
 * to accept hostnames, as this depends on the availability of DNS services.
 * Since many embedded deployments do not have name services, this should
 * not be relied upon.
 *
 * @param  Addr         The address buffer to initialize
 * @param  string       The string to initialize the address from.
 * @returns OS_SUCCESS if successful
 */
int32 OS_SocketAddrFromString(OS_SockAddr_t *Addr, const char *string);

/**
 * Get the port number of a network address
 *
 * For network prototcols that have the concept of a port number (such
 * as TCP/IP and UDP/IP) this function gets the port number from the
 * address structure.
 *
 * @param  PortNum      Buffer to store the port number
 * @param  Addr         The network address buffer
 * @returns OS_SUCCESS if successful
 */
int32 OS_SocketAddrGetPort(uint16 *PortNum, const OS_SockAddr_t *Addr);

/**
 * Get the port number of a network address
 *
 * For network prototcols that have the concept of a port number (such
 * as TCP/IP and UDP/IP) this function gets the port number from the
 * address structure.
 *
 * @param  PortNum      Buffer to store the port number
 * @param  Addr         The network address buffer
 * @returns OS_SUCCESS if successful
 */
int32 OS_SocketAddrSetPort(OS_SockAddr_t *Addr, uint16 PortNum);



/*
 * --------------------------------------------------------------------------------------
 * Sockets API Functions
 *
 * These functions are loosely related to the BSD Sockets API but made to be
 * more consistent with other OSAL API functions.  That is, they operate on
 * OSAL IDs (32-bit opaque number values) and return an OSAL error code.
 *
 * OSAL Socket IDs are very closely related to File IDs and share the same ID
 * number space.  Additionally, the file OS_read() / OS_write() / OS_close()
 * calls also work on sockets.
 *
 * Note that all of functions may return OS_ERROR_NOT_IMPLEMENTED if network support
 * is not configured at compile time.
 * --------------------------------------------------------------------------------------
 */

/**
 * Opens a socket.
 *
 * A new, unconnected and unbound socket is allocated of the given domain and type.
 *
 * @param  sock_id  Buffer to hold the OSAL ID
 * @param  Domain   The domain / address family of the socket (INET or INET6, etc)
 * @param  Type     The type of the socket (STREAM or DATAGRAM)
 * @returns OS_SUCCESS if successful
 */
int32 OS_SocketOpen(uint32 *sock_id, OS_SocketDomain_t Domain, OS_SocketType_t Type);

/**
 * Binds a socket to a given local address.
 *
 * The specified socket will be bound to the local address and port, if available.
 *
 * If the socket is connectionless, then it only binds to the local address.
 *
 * If the socket is connection-oriented (stream), then this will also put the
 * socket into a listening state for incoming connections at the local address.
 *
 * @param  sock_id  The socket ID
 * @param  Addr     The local address to bind to
 * @returns OS_SUCCESS if successful
 */
int32 OS_SocketBind(uint32 sock_id, const OS_SockAddr_t *Addr);

/**
 * Connects a socket to a given remote address.
 *
 * The socket will be connected to the remote address and port, if available.
 * This only applies to stream-oriented sockets.  Calling this on a datagram
 * socket will return an error (these sockets should use SendTo/RecvFrom).
 *
 * @param  sock_id  The socket ID
 * @param  Addr     The remote address to connect to
 * @param  timeout  The maximum amount of time to wait, or OS_PEND to wait forever
 * @returns OS_SUCCESS if successful
 */
int32 OS_SocketConnect(uint32 sock_id, const OS_SockAddr_t *Addr, int32 timeout);

/**
 * Waits for and accept the next incoming connection on the given socket
 *
 * This is used for sockets operating in a "server" role.  The socket must be
 * a stream type (connection-oriented) and previously bound to a local address
 * using OS_SocketBind().  This will block the caller up to the given timeout
 * or until an incoming connection request occurs, whichever happens first.
 *
 * The new stream connection is then returned to the caller and the original
 * server socket ID can be reused for the next connection.
 *
 * @param  sock_id      The server socket ID, previously bound using OS_SocketBind()
 * @param  connsock_id  The connection socket, a new ID that can be read/written
 * @param  Addr         The remote address of the incoming connection
 * @param  timeout      The maximum amount of time to wait, or OS_PEND to wait forever
 * @returns OS_SUCCESS if successful
 */
int32 OS_SocketAccept(uint32 sock_id, uint32 *connsock_id, OS_SockAddr_t *Addr, int32 timeout);

/**
 * Reads data from a message-oriented (datagram) socket
 *
 * If a message is already available on the socket, this should immediately return
 * that data without blocking.  Otherwise, it may block up to the given timeout.
 *
 * @param  sock_id      The socket ID, previously bound using OS_SocketBind()
 * @param  buffer       Pointer to message data receive buffer
 * @param  buflen       The maximum length of the message data to receive
 * @param  RemoteAddr   Buffer to store the remote network address (may be NULL)
 * @param  timeout      The maximum amount of time to wait, or OS_PEND to wait forever
 * @returns OS_SUCCESS if successful
 */
int32 OS_SocketRecvFrom(uint32 sock_id, void *buffer, uint32 buflen, OS_SockAddr_t *RemoteAddr, int32 timeout);

/**
 * Sends data to a message-oriented (datagram) socket
 *
 * This sends data in a non-blocking mode.  If the socket is not currently able to
 * queue the message, such as if its outbound buffer is full, then this returns
 * an error code.
 *
 * @param  sock_id      The socket ID, which must be of the datagram type
 * @param  buffer       Pointer to message data to send
 * @param  buflen       The length of the message data to send
 * @param  RemoteAddr   Buffer containing the remote network address to send to
 * @returns OS_SUCCESS if successful
 */
int32 OS_SocketSendTo(uint32 sock_id, const void *buffer, uint32 buflen, const OS_SockAddr_t *RemoteAddr);

/**
 * Gets an OSAL ID from a given name
 *
 * OSAL Sockets use generated names according to the address and type.
 *
 * @sa OS_SocketGetInfo()
 *
 * @param  sock_id      Buffer to hold result
 * @param  sock_name    Name of socket to find
 * @returns OS_SUCCESS if successful
 */
int32 OS_SocketGetIdByName (uint32 *sock_id, const char *sock_name);

/**
 * Gets information about an OSAL Socket ID
 *
 * OSAL Sockets use generated names according to the address and type.
 * This allows applications to find the name of a given socket.
 *
 * @param  sock_id      The socket ID
 * @param  sock_prop    Buffer to hold socket information
 * @returns OS_SUCCESS if successful
 */
int32 OS_SocketGetInfo (uint32 sock_id, OS_socket_prop_t *sock_prop);


/*
** OS_NetworkGetID is currently [[deprecated]] as its behavior is
** unknown and not consistent across operating systems.
*/

/************************************************************************/
/** \brief Get network id
**
**  \par Description
**       Gets the ID of the current Network 
**
**  \par Assumptions, External Events, and Notes:
**       None
**
**  \param [in]   Mode    #OS_RunTimeModeEnum_t
**  
**  \returns
**      OS_ERROR if the  host id could not be found
        32 bit host id if success
**  \endreturns
**
*************************************************************************/
int32 OS_NetworkGetID             (void);

/************************************************************************/
/** \brief Get network hostname
**
**  \par Description
**       Gets the name of the current host
**
**  \par Assumptions, External Events, and Notes:
**       None
**
**  \param [in/out]   host_name      Name of host
**  \param [in]       name_len       Max length of name
**  
**  \returns
**  \retcode #OS_SUCCESS  \retdesc \copydoc OS_SUCCESS \endcode
**  \retcode #OS_ERROR  \retdesc \copydoc OS_ERROR \endcode
**  \endreturns
**
*************************************************************************/
int32 OS_NetworkGetHostName       (char *host_name, uint32 name_len);

#endif
