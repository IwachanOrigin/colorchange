
set(main_src
  main.cpp
  mainwindow.h
  mainwindow.cpp
)

add_executable(
  "colorchange_ysh"
  WIN32
  ${main_src}
  ${UI_FILES}
  ${RC_FILES}
  ${QRC_FILES}
)

# Link
target_link_libraries(
  "colorchange_ysh"
  Qt5::Widgets
)

