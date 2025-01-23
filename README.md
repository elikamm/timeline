# Timeline
A jump-and-run game with an additional axis: Time.

## Compile and Run (Linux/macOS)
**Timeline** utilizes the _CMake_ build system.  
You can run `./build_and_run.sh` or follow the steps below to compile and run the **Timeline** executable:
1.  Compile
    ```bash
    mkdir build
    cd build
    cmake ..
    cmake --build . --config Release
    ```
2.  Run (inside the `build` directory)
    ```bash
    ./timeline
    ```

## Compile and Run (Windows)
**Timeline** utilizes the _CMake_ build system.  
You can run `.\build_and_run.bat` or follow the steps below to compile and run the **Timeline** executable:
1.  Compile
    ```batch
    if not exist build md build
    cd build
    cmake ..
    cmake --build . --config Release
    ```
2.  Run (inside the `build\Release` directory)
    ```batch
    .\timeline.exe
    ```

## External Libraries

- [Raylib](https://www.raylib.com/) by [raysan5](https://github.com/raysan5)