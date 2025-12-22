find_package(Doxygen REQUIRED)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(DoxygenUtilities)

# ------------------------
# Doxygen targets
# ------------------------
add_doxygen_target(
    core_lib_docs
    "Core Library"
    "${CMAKE_SOURCE_DIR}/lib/core"
    "${CMAKE_BINARY_DIR}/docs/lib/core"
)

add_doxygen_target(
    firmware_gpio_lib_docs
    "GPIO Library"
    "${CMAKE_SOURCE_DIR}/firmware/lib/gpio"
    "${CMAKE_BINARY_DIR}/docs/firmware/lib/gpio"
)

# ------------------------
# Bridge page
# ------------------------
# Variables for template
set(PROJECT_NAME "Motor Control")
set(PROJECT_DESC "A project to experiment with motor control.")
set(GITHUB_REPO_URL "https://github.com/jackcenter/motor_project")

# Bridge page HTML content
set(DOC_MODULES "")
string(APPEND DOC_MODULES "<ul>\n")
string(APPEND DOC_MODULES "<li><a href=\"lib/core/html/index.html\">Core Library</a></li>\n")
string(APPEND DOC_MODULES "<li><a href=\"firmware/lib/gpio/html/index.html\">GPIO Library</a></li>\n")
string(APPEND DOC_MODULES "</ul>\n")

set(PROJECT_LINKS "")
string(APPEND PROJECT_LINKS "<ul>\n")
string(APPEND PROJECT_LINKS "<li><a href=\"https://github.com/jackcenter/motor_project\">GitHub Repository</a></li>\n")
string(APPEND PROJECT_LINKS "</ul>\n")

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/index.html.in
    ${CMAKE_BINARY_DIR}/docs/index.html
    @ONLY
)

add_custom_target(docs ALL
    DEPENDS core_lib_docs firmware_gpio_lib_docs
    COMMENT "Generating documentation landing page"
)
