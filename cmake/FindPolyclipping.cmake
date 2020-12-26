set(POLYCLIPPING_SUBMODULE_BASEPATH "${PROJECT_SOURCE_DIR}/libs/polyclipping")
if(EXISTS "${POLYCLIPPING_SUBMODULE_BASEPATH}" AND NOT UNBUNDLE_POLYCLIPPING AND NOT UNBUNDLE_ALL)
    message(STATUS "Using vendored Polyclipping")

    # Add library
    add_subdirectory(
        "${POLYCLIPPING_SUBMODULE_BASEPATH}"
        "${CMAKE_BINARY_DIR}/libs/polyclipping"
        EXCLUDE_FROM_ALL
    )

    # Stop here, we're done
    return()
endif()

# TODO: Find unbundled variant via pkg-config
