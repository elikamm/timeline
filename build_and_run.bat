if not exist build md build
cd build
cmake ..
cmake --build . --config Release
.\Release\timeline.exe