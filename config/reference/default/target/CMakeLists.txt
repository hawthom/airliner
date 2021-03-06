include(../set-vars.cmake)

# Put target specific functions here.  This is where we build most everything.  Everything that either uses the
# cross toolchain or has target independent functions.

initialize_airliner_build(
    PSP ${TARGET_PSP}
    OSAL ${TARGET_OSAL}
    CORE_TOOLS ${CMAKE_CURRENT_SOURCE_DIR}/tools
    CONFIG
        ${PROJECT_SOURCE_DIR}/core/mission_inc/
        ${PROJECT_SOURCE_DIR}/core/platform_inc/
    FILESYS
        /cf/apps
        /cf/download
        /cf/log
        /cf/upload
        /ram
    STARTUP_SCRIPT
        ${CMAKE_CURRENT_SOURCE_DIR}/cfe_es_startup.scr
    
    CONFIG_SOURCES
        ${PROJECT_SOURCE_DIR}/core/mission_inc/cfe_mission_cfg.h
        ${PROJECT_SOURCE_DIR}/core/mission_inc/cfe_msgids.h
        ${PROJECT_SOURCE_DIR}/core/platform_inc/osconfig.h
        ${PROJECT_SOURCE_DIR}/core/platform_inc/cfe_platform_cfg.h
        
    REFERENCE
)



add_airliner_app(
    cfs_lib
    DEFINITION ${PROJECT_SOURCE_DIR}/apps/cfs_lib/fsw/for_build
)

add_airliner_app(
    px4lib
    DEFINITION ${PROJECT_SOURCE_DIR}/apps/px4lib/fsw/for_build
)

add_airliner_app(
    pblib
    DEFINITION ${PROJECT_SOURCE_DIR}/apps/pblib/fsw/for_build
)

add_airliner_app(
    prmlib
    DEFINITION ${PROJECT_SOURCE_DIR}/apps/prmlib/fsw/for_build
)

add_airliner_app(
    sim
    DEFINITION ${PROJECT_SOURCE_DIR}/apps/sim/fsw/for_build
)

add_airliner_app(
    sch
    DEFINITION ${PROJECT_SOURCE_DIR}/apps/sch/fsw/for_build
    CONFIG_SOURCES
        ${PROJECT_SOURCE_DIR}/apps/sch/fsw/mission_inc/sch_perfids.h
        ${PROJECT_SOURCE_DIR}/apps/sch/fsw/platform_inc/sch_msgids.h
        ${PROJECT_SOURCE_DIR}/apps/sch/fsw/platform_inc/sch_platform_cfg.h
)

add_airliner_app(
    cf
    DEFINITION ${PROJECT_SOURCE_DIR}/apps/cf/fsw/for_build
    CONFIG_SOURCES
        ${PROJECT_SOURCE_DIR}/apps/cf/fsw/mission_inc/cf_perfids.h
        ${PROJECT_SOURCE_DIR}/apps/cf/fsw/platform_inc/cf_msgids.h
        ${PROJECT_SOURCE_DIR}/apps/cf/fsw/platform_inc/cf_platform_cfg.h
    )

add_airliner_app(
    cs
    DEFINITION ${PROJECT_SOURCE_DIR}/apps/cs/fsw/for_build
    CONFIG_SOURCES
        ${PROJECT_SOURCE_DIR}/apps/cs/fsw/mission_inc/cs_mission_cfg.h
        ${PROJECT_SOURCE_DIR}/apps/cs/fsw/mission_inc/cs_perfids.h
        ${PROJECT_SOURCE_DIR}/apps/cs/fsw/platform_inc/cs_msgids.h
        ${PROJECT_SOURCE_DIR}/apps/cs/fsw/platform_inc/cs_platform_cfg.h
)

add_airliner_app(
    ds
    DEFINITION ${PROJECT_SOURCE_DIR}/apps/ds/fsw/for_build
    CONFIG_SOURCES
        ${PROJECT_SOURCE_DIR}/apps/ds/fsw/mission_inc/ds_perfids.h
        ${PROJECT_SOURCE_DIR}/apps/ds/fsw/platform_inc/ds_msgids.h
        ${PROJECT_SOURCE_DIR}/apps/ds/fsw/platform_inc/ds_platform_cfg.h
)

add_airliner_app(
    fm
    DEFINITION ${PROJECT_SOURCE_DIR}/apps/fm/fsw/for_build
    CONFIG_SOURCES
        ${PROJECT_SOURCE_DIR}/apps/fm/fsw/mission_inc/fm_perfids.h
        ${PROJECT_SOURCE_DIR}/apps/fm/fsw/platform_inc/fm_msgids.h
        ${PROJECT_SOURCE_DIR}/apps/fm/fsw/platform_inc/fm_platform_cfg.h
)

add_airliner_app(
    hk
    DEFINITION ${PROJECT_SOURCE_DIR}/apps/hk/fsw/for_build
    CONFIG_SOURCES
        ${PROJECT_SOURCE_DIR}/apps/hk/fsw/mission_inc/hk_perfids.h
        ${PROJECT_SOURCE_DIR}/apps/hk/fsw/platform_inc/hk_msgids.h
        ${PROJECT_SOURCE_DIR}/apps/hk/fsw/platform_inc/hk_platform_cfg.h
)

add_airliner_app(
    hs
    DEFINITION ${PROJECT_SOURCE_DIR}/apps/hs/fsw/for_build
    CONFIG_SOURCES
        ${PROJECT_SOURCE_DIR}/apps/hs/fsw/mission_inc/hs_perfids.h
        ${PROJECT_SOURCE_DIR}/apps/hs/fsw/platform_inc/hs_msgids.h
        ${PROJECT_SOURCE_DIR}/apps/hs/fsw/platform_inc/hs_platform_cfg.h
)

add_airliner_app(
    lc
    DEFINITION ${PROJECT_SOURCE_DIR}/apps/lc/fsw/for_build
    CONFIG_SOURCES
        ${PROJECT_SOURCE_DIR}/apps/lc/fsw/mission_inc/lc_mission_cfg.h
        ${PROJECT_SOURCE_DIR}/apps/lc/fsw/mission_inc/lc_perfids.h
        ${PROJECT_SOURCE_DIR}/apps/lc/fsw/platform_inc/lc_msgids.h
        ${PROJECT_SOURCE_DIR}/apps/lc/fsw/platform_inc/lc_platform_cfg.h
)

add_airliner_app(
    md
    DEFINITION ${PROJECT_SOURCE_DIR}/apps/md/fsw/for_build
    CONFIG_SOURCES
        ${PROJECT_SOURCE_DIR}/apps/md/fsw/mission_inc/md_perfids.h
        ${PROJECT_SOURCE_DIR}/apps/md/fsw/platform_inc/md_msgids.h
        ${PROJECT_SOURCE_DIR}/apps/md/fsw/platform_inc/md_platform_cfg.h
)

add_airliner_app(
    mm
    DEFINITION ${PROJECT_SOURCE_DIR}/apps/mm/fsw/for_build
    CONFIG_SOURCES
        ${PROJECT_SOURCE_DIR}/apps/mm/fsw/mission_inc/mm_mission_cfg.h
        ${PROJECT_SOURCE_DIR}/apps/mm/fsw/mission_inc/mm_perfids.h
        ${PROJECT_SOURCE_DIR}/apps/mm/fsw/platform_inc/mm_msgids.h
        ${PROJECT_SOURCE_DIR}/apps/mm/fsw/platform_inc/mm_platform_cfg.h
)

add_airliner_app(
    sc
    DEFINITION ${PROJECT_SOURCE_DIR}/apps/sc/fsw/for_build
    CONFIG_SOURCES
        ${PROJECT_SOURCE_DIR}/apps/sc/fsw/mission_inc/sc_perfids.h
        ${PROJECT_SOURCE_DIR}/apps/sc/fsw/platform_inc/sc_msgids.h
        ${PROJECT_SOURCE_DIR}/apps/sc/fsw/platform_inc/sc_platform_cfg.h
)

add_airliner_app(
    ci
    DEFINITION ${PROJECT_SOURCE_DIR}/apps/ci/fsw/for_build
    CONFIG_SOURCES
        ${PROJECT_SOURCE_DIR}/apps/ci/fsw/mission_inc/ci_mission_cfg.h
        ${PROJECT_SOURCE_DIR}/apps/ci/fsw/mission_inc/ci_perfids.h
        ${PROJECT_SOURCE_DIR}/apps/ci/fsw/platform_inc/ci_msgids.h
        ${PROJECT_SOURCE_DIR}/apps/ci/fsw/platform_inc/ci_platform_cfg.h
)

add_airliner_app(
    to
    DEFINITION ${PROJECT_SOURCE_DIR}/apps/to/fsw/for_build
    CONFIG_SOURCES
        ${PROJECT_SOURCE_DIR}/apps/to/fsw/mission_inc/to_mission_cfg.h
        ${PROJECT_SOURCE_DIR}/apps/to/fsw/mission_inc/to_perfids.h
        ${PROJECT_SOURCE_DIR}/apps/to/fsw/platform_inc/to_msgids.h
        ${PROJECT_SOURCE_DIR}/apps/to/fsw/platform_inc/to_platform_cfg.h
)

add_airliner_app(
    ea
    DEFINITION ${PROJECT_SOURCE_DIR}/apps/ea/fsw/for_build
    CONFIG_SOURCES
        ${PROJECT_SOURCE_DIR}/apps/ea/fsw/mission_inc/ea_mission_cfg.h
        ${PROJECT_SOURCE_DIR}/apps/ea/fsw/mission_inc/ea_perfids.h
        ${PROJECT_SOURCE_DIR}/apps/ea/fsw/platform_inc/ea_msgids.h
        ${PROJECT_SOURCE_DIR}/apps/ea/fsw/platform_inc/ea_platform_cfg.h
)

add_airliner_app(
    vc
    DEFINITION ${PROJECT_SOURCE_DIR}/apps/vc/fsw/for_build
    CONFIG_SOURCES
        ${PROJECT_SOURCE_DIR}/apps/vc/fsw/mission_inc/vc_mission_cfg.h
        ${PROJECT_SOURCE_DIR}/apps/vc/fsw/mission_inc/vc_perfids.h
        ${PROJECT_SOURCE_DIR}/apps/vc/fsw/platform_inc/vc_msgids.h
        ${PROJECT_SOURCE_DIR}/apps/vc/fsw/platform_inc/vc_platform_cfg.h
)

add_airliner_app(
    amc
    DEFINITION ${PROJECT_SOURCE_DIR}/apps/amc/fsw/for_build
    INCLUDES
        ${PROJECT_SOURCE_DIR}/apps/px4lib/fsw/platform_inc
        ${PROJECT_SOURCE_DIR}/apps/prmlib/fsw/platform_inc
    CONFIG_SOURCES
        ${PROJECT_SOURCE_DIR}/apps/amc/fsw/platform_inc/amc_platform_cfg.h
        ${PROJECT_SOURCE_DIR}/apps/amc/fsw/platform_inc/amc_msgids.h
        ${PROJECT_SOURCE_DIR}/apps/amc/fsw/mission_inc/amc_perfids.h
)

add_airliner_app(
    mac
    DEFINITION ${PROJECT_SOURCE_DIR}/apps/mac/fsw/for_build
    INCLUDES
        ${PROJECT_SOURCE_DIR}/apps/px4lib/fsw/platform_inc
        ${PROJECT_SOURCE_DIR}/apps/prmlib/fsw/platform_inc
    CONFIG_SOURCES
        ${PROJECT_SOURCE_DIR}/apps/mac/fsw/platform_inc/mac_platform_cfg.h
        ${PROJECT_SOURCE_DIR}/apps/mac/fsw/platform_inc/mac_msgids.h
        ${PROJECT_SOURCE_DIR}/apps/mac/fsw/mission_inc/mac_perfids.h
)

add_airliner_app(
    ulr
    DEFINITION ${PROJECT_SOURCE_DIR}/apps/ulr/fsw/for_build
    CONFIG_SOURCES
        ${PROJECT_SOURCE_DIR}/apps/ulr/fsw/platform_inc/ulr_platform_cfg.h
        ${PROJECT_SOURCE_DIR}/apps/ulr/fsw/platform_inc/ulr_msgids.h
        ${PROJECT_SOURCE_DIR}/apps/ulr/fsw/mission_inc/ulr_perfids.h
)

add_airliner_app(
    rgbled
    DEFINITION ${PROJECT_SOURCE_DIR}/apps/rgbled/fsw/for_build
    CONFIG_SOURCES
        ${PROJECT_SOURCE_DIR}/apps/rgbled/fsw/platform_inc/rgbled_platform_cfg.h
        ${PROJECT_SOURCE_DIR}/apps/rgbled/fsw/platform_inc/rgbled_msgids.h
        ${PROJECT_SOURCE_DIR}/apps/rgbled/fsw/mission_inc/rgbled_perfids.h
)

add_airliner_app(
    ms5611
    DEFINITION ${PROJECT_SOURCE_DIR}/apps/ms5611/fsw/for_build
    CONFIG_SOURCES
        ${PROJECT_SOURCE_DIR}/apps/ms5611/fsw/platform_inc/ms5611_platform_cfg.h
        ${PROJECT_SOURCE_DIR}/apps/ms5611/fsw/platform_inc/ms5611_msgids.h
        ${PROJECT_SOURCE_DIR}/apps/ms5611/fsw/mission_inc/ms5611_perfids.h
)

add_airliner_app(
    gps
    DEFINITION ${PROJECT_SOURCE_DIR}/apps/gps/fsw/for_build
    CONFIG_SOURCES
        ${PROJECT_SOURCE_DIR}/apps/gps/fsw/platform_inc/gps_platform_cfg.h
        ${PROJECT_SOURCE_DIR}/apps/gps/fsw/platform_inc/gps_msgids.h
        ${PROJECT_SOURCE_DIR}/apps/gps/fsw/mission_inc/gps_perfids.h
)

add_airliner_app(
    sens
    DEFINITION ${PROJECT_SOURCE_DIR}/apps/sens/fsw/for_build
    CONFIG_SOURCES
        ${PROJECT_SOURCE_DIR}/apps/sens/fsw/platform_inc/sens_platform_cfg.h
        ${PROJECT_SOURCE_DIR}/apps/sens/fsw/platform_inc/sens_msgids.h
        ${PROJECT_SOURCE_DIR}/apps/sens/fsw/mission_inc/sens_perfids.h
)

add_airliner_app(
    mpc
    DEFINITION ${PROJECT_SOURCE_DIR}/apps/mpc/fsw/for_build
    CONFIG_SOURCES
        ${PROJECT_SOURCE_DIR}/apps/mpc/fsw/platform_inc/mpc_platform_cfg.h
        ${PROJECT_SOURCE_DIR}/apps/mpc/fsw/platform_inc/mpc_msgids.h
        ${PROJECT_SOURCE_DIR}/apps/mpc/fsw/mission_inc/mpc_perfids.h
)

add_airliner_app(
    vm
    DEFINITION ${PROJECT_SOURCE_DIR}/apps/vm/fsw/for_build
    CONFIG_SOURCES
        ${PROJECT_SOURCE_DIR}/apps/vm/fsw/platform_inc/vm_platform_cfg.h
        ${PROJECT_SOURCE_DIR}/apps/vm/fsw/platform_inc/vm_msgids.h
        ${PROJECT_SOURCE_DIR}/apps/vm/fsw/mission_inc/vm_perfids.h
)

add_airliner_app(
    ld
    DEFINITION ${PROJECT_SOURCE_DIR}/apps/ld/fsw/for_build
    CONFIG_SOURCES
        ${PROJECT_SOURCE_DIR}/apps/ld/fsw/platform_inc/ld_platform_cfg.h
        ${PROJECT_SOURCE_DIR}/apps/ld/fsw/platform_inc/ld_msgids.h
        ${PROJECT_SOURCE_DIR}/apps/ld/fsw/mission_inc/ld_perfids.h
)

add_airliner_app(
    nav
    DEFINITION ${PROJECT_SOURCE_DIR}/apps/nav/fsw/for_build
    CONFIG_SOURCES
        ${PROJECT_SOURCE_DIR}/apps/nav/fsw/platform_inc/nav_platform_cfg.h
        ${PROJECT_SOURCE_DIR}/apps/nav/fsw/platform_inc/nav_msgids.h
        ${PROJECT_SOURCE_DIR}/apps/nav/fsw/mission_inc/nav_perfids.h
)

add_airliner_app(
    rcin
    DEFINITION ${PROJECT_SOURCE_DIR}/apps/rcin/fsw/for_build
    CONFIG_SOURCES
        ${PROJECT_SOURCE_DIR}/apps/rcin/fsw/platform_inc/rcin_platform_cfg.h
        ${PROJECT_SOURCE_DIR}/apps/rcin/fsw/platform_inc/rcin_msgids.h
        ${PROJECT_SOURCE_DIR}/apps/rcin/fsw/mission_inc/rcin_perfids.h
)

add_airliner_app(
    bat
    DEFINITION ${PROJECT_SOURCE_DIR}/apps/bat/fsw/for_build
    CONFIG_SOURCES
        ${PROJECT_SOURCE_DIR}/apps/bat/fsw/platform_inc/bat_platform_cfg.h
        ${PROJECT_SOURCE_DIR}/apps/bat/fsw/platform_inc/bat_msgids.h
        ${PROJECT_SOURCE_DIR}/apps/bat/fsw/mission_inc/bat_perfids.h
)

add_airliner_app(
    mpu9250
    DEFINITION ${PROJECT_SOURCE_DIR}/apps/mpu9250/fsw/for_build
    CONFIG_SOURCES
        ${PROJECT_SOURCE_DIR}/apps/mpu9250/fsw/platform_inc/mpu9250_platform_cfg.h
        ${PROJECT_SOURCE_DIR}/apps/mpu9250/fsw/platform_inc/mpu9250_msgids.h
        ${PROJECT_SOURCE_DIR}/apps/mpu9250/fsw/mission_inc/mpu9250_perfids.h
)

add_airliner_app(
    hmc5883
    DEFINITION ${PROJECT_SOURCE_DIR}/apps/hmc5883/fsw/for_build
    CONFIG_SOURCES
        ${PROJECT_SOURCE_DIR}/apps/hmc5883/fsw/platform_inc/hmc5883_platform_cfg.h
        ${PROJECT_SOURCE_DIR}/apps/hmc5883/fsw/platform_inc/hmc5883_msgids.h
        ${PROJECT_SOURCE_DIR}/apps/hmc5883/fsw/mission_inc/hmc5883_perfids.h
)

add_airliner_app(
    pe
    DEFINITION ${PROJECT_SOURCE_DIR}/apps/pe/fsw/for_build
    CONFIG_SOURCES
        ${PROJECT_SOURCE_DIR}/apps/pe/fsw/platform_inc/pe_platform_cfg.h
        ${PROJECT_SOURCE_DIR}/apps/pe/fsw/platform_inc/pe_msgids.h
        ${PROJECT_SOURCE_DIR}/apps/pe/fsw/mission_inc/pe_perfids.h
)

add_airliner_app(
    qae
    DEFINITION ${PROJECT_SOURCE_DIR}/apps/qae/fsw/for_build
    CONFIG_SOURCES
        ${PROJECT_SOURCE_DIR}/apps/qae/fsw/platform_inc/qae_platform_cfg.h
        ${PROJECT_SOURCE_DIR}/apps/qae/fsw/platform_inc/qae_msgids.h
        ${PROJECT_SOURCE_DIR}/apps/qae/fsw/mission_inc/qae_perfids.h
)

add_airliner_app(
    lgc
    DEFINITION ${PROJECT_SOURCE_DIR}/apps/lgc/fsw/for_build
    CONFIG_SOURCES
        ${PROJECT_SOURCE_DIR}/apps/lgc/fsw/platform_inc/lgc_platform_cfg.h
        ${PROJECT_SOURCE_DIR}/apps/lgc/fsw/platform_inc/lgc_msgids.h
        ${PROJECT_SOURCE_DIR}/apps/lgc/fsw/mission_inc/lgc_perfids.h
)
