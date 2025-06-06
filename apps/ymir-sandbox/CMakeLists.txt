## Create the executable target
add_executable(ymir-sandbox
    src/main.cpp
)
add_executable(ymir::ymir-sandbox ALIAS ymir-sandbox)
set_target_properties(ymir-sandbox PROPERTIES
                      VERSION ${Ymir_VERSION}
                      SOVERSION ${Ymir_VERSION_MAJOR})
target_include_directories(ymir-sandbox
    PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    PRIVATE "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>"
)
target_link_libraries(ymir-sandbox PRIVATE ymir::ymir-core SDL3::SDL3)
target_compile_features(ymir-sandbox PUBLIC cxx_std_20)

## Add dependencies
target_link_libraries(ymir-sandbox PRIVATE fmt)

cmrk_copy_runtime_dlls(ymir-sandbox)

if (IPO_SUPPORTED AND Ymir_ENABLE_IPO)
    message(STATUS "Enabling IPO / LTO for ymir-sandbox")
    set_property(TARGET ymir-sandbox PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
endif()

## Apply performance options
if (Ymir_AVX2)
    if (MSVC)
        target_compile_options(ymir-sandbox PUBLIC "/arch:AVX2")
    else ()
        target_compile_options(ymir-sandbox PUBLIC "-mavx2")
        target_compile_options(ymir-sandbox PUBLIC "-mfma")
        target_compile_options(ymir-sandbox PUBLIC "-mbmi")
    endif ()
endif ()

## Configure Visual Studio solution
if (MSVC)
    vs_set_filters(TARGET ymir-sandbox)
    set_target_properties(ymir-sandbox PROPERTIES FOLDER "Ymir")
endif ()

## No packaging for this project as it's meant to be testing grounds
