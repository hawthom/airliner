set(APP_NAME cs)

add_airliner_app_table(
    ${APP_NAME}
    NAME cs_apptbl
    SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/tables/cs_apptbl.c
    INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/src/
)

add_airliner_app_table(
    ${APP_NAME}
    NAME cs_eepromtbl
    SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/tables/cs_eepromtbl.c
    INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/src/
)

add_airliner_app_table(
    ${APP_NAME}
    NAME cs_memorytbl
    SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/tables/cs_memorytbl.c
    INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/src/
)

add_airliner_app_table(
    ${APP_NAME}
    NAME cs_tablestbl
    SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/tables/cs_tablestbl.c
    INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/src/
)


