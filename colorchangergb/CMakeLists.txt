
set(main_src
  main.cpp
  mainwindow.h
  mainwindow.cpp
)

add_executable(
  "colorchange_rgb"
  WIN32
  ${main_src}
  ${UI_FILES}
  ${RC_FILES}
  ${QRC_FILES}
)

# Link
target_link_libraries(
  "colorchange_rgb"
  Qt5::Widgets
)

