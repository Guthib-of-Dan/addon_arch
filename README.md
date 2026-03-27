# Very basic C++ native addons for NodeJS
Currently this repo includes basic setup for V8 and N-API in C++.
## Special feature - compile\_commands.json
This means support for NeoVim + clangd
## Usage
Use this repo as a "template" in GitHub, run (I use Bun for this) "bun run cxx:fetch" to install all headers for current NodeJS version + set all CMake paths. "bun run cxx:conf" configures build and compile\_commands.json, "bun run cxx:build" build the binaries.
## Coming soon
Vitest tests (like github.com/Guthib-of-Dan/lib\_arch), VCPKG config, mutli-version builds for V8, GitHub CI/CD (+ npm publishing)
