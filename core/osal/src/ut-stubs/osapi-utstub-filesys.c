/*
 *  NASA Docket No. GSC-18,370-1, and identified as "Operating System Abstraction Layer"
 *
 *  Copyright (c) 2019 United States Government as represented by
 *  the Administrator of the National Aeronautics and Space Administration.
 *  All Rights Reserved.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

/**
 * \file osapi_stubs.c
 *
 *  Created on: Feb 25, 2015
 *      Author: joseph.p.hickey@nasa.gov
 *
 * Stub implementations for the functions defined in the OSAL API
 *
 * The stub implementation can be used for unit testing applications built
 * on top of OSAL.  The stubs do not do any real function, but allow
 * the return code to be crafted such that error paths in the application
 * can be executed.
 */

#include "utstub-helpers.h"


UT_DEFAULT_STUB(OS_FileSysAPI_Init,(void))


/*****************************************************************************
 *
 * Stub function for OS_mkfs()
 *
 *****************************************************************************/
int32 OS_mkfs(char *address, const char *devname, const char * volname, uint32 blocksize,
              uint32 numblocks)
{
    int32 status;

    status = UT_DEFAULT_IMPL(OS_mkfs);

    return status;
}

/*****************************************************************************
 *
 * Stub function for OS_rmfs()
 *
 *****************************************************************************/
int32 OS_rmfs(const char *devname)
{
    int32 status;

    status = UT_DEFAULT_IMPL(OS_rmfs);

    return status;
}

/*****************************************************************************
 *
 * Stub function for OS_initfs()
 *
 *****************************************************************************/
int32 OS_initfs(char *address, const char *devname, const char *volname,
                uint32 blocksize, uint32 numblocks)
{
    int32 status;

    status = UT_DEFAULT_IMPL(OS_initfs);

    return status;
}

/*****************************************************************************
 *
 * Stub function for OS_mount()
 *
 *****************************************************************************/
int32 OS_mount(const char *devname, const char* mountpoint)
{
    int32 status;

    status = UT_DEFAULT_IMPL(OS_mount);

    return status;
}

/*****************************************************************************
 *
 * Stub function for OS_unmount()
 *
 *****************************************************************************/
int32 OS_unmount(const char *mountpoint)
{
    int32 status;

    status = UT_DEFAULT_IMPL(OS_unmount);

    return status;
}

/*****************************************************************************
 *
 * Stub function for OS_fsBlocksFree()
 *
 *****************************************************************************/
int32 OS_fsBlocksFree(const char *name)
{
    int32 status;

    status = UT_DEFAULT_IMPL_RC(OS_fsBlocksFree, 100);

    return status;
}

/*****************************************************************************
 *
 * Stub function for OS_fsBytesFree()
 *
 *****************************************************************************/
int32 OS_fsBytesFree(const char *name, uint64 *bytes_free)
{
    int32 status;

    status = UT_DEFAULT_IMPL(OS_fsBytesFree);

    if (status == OS_SUCCESS &&
            UT_Stub_CopyToLocal(UT_KEY(OS_fsBytesFree), bytes_free, sizeof(*bytes_free)) < sizeof(*bytes_free))
    {
        *bytes_free = 10000;
    }

    return status;
}

/*****************************************************************************
 *
 * Stub function for OS_chkfs()
 *
 *****************************************************************************/
int32 OS_chkfs(const char *name, bool repair)
{
    int32 status;

    status = UT_DEFAULT_IMPL(OS_chkfs);

    return status;
}

/*****************************************************************************
 *
 * Stub function for OS_FS_GetPhysDriveName()
 *
 *****************************************************************************/
int32 OS_FS_GetPhysDriveName(char * PhysDriveName, const char * MountPoint)
{
    int32 status;

    status = UT_DEFAULT_IMPL(OS_FS_GetPhysDriveName);
    strncpy(PhysDriveName, MountPoint, OS_FS_PHYS_NAME_LEN);

    return status;
}

/*****************************************************************************
 *
 * Stub function for OS_GetFsInfo()
 *
 *****************************************************************************/
int32 OS_GetFsInfo(os_fsinfo_t  *FilesysInfo)
{
    int32 status;

    status = UT_DEFAULT_IMPL(OS_GetFsInfo);
    memset(FilesysInfo, 0, sizeof (*FilesysInfo));

    return status;
}

/*****************************************************************************
 *
 * Stub function for OS_TranslatePath()
 *
 *****************************************************************************/
int32 OS_TranslatePath( const char *VirtualPath, char *LocalPath)
{
    int32 status;

    status = UT_DEFAULT_IMPL(OS_TranslatePath);

    if (status == OS_SUCCESS &&
            UT_Stub_CopyToLocal(UT_KEY(OS_TranslatePath), LocalPath, OS_MAX_LOCAL_PATH_LEN) == 0)
    {
        strncpy(LocalPath, VirtualPath, OS_MAX_LOCAL_PATH_LEN);
    }

    return status;
}


