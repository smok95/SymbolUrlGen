## SymbolUrlGenerator

SymbolUrlGenerator is a simple tool that generates the URL for the debug symbol file of a given file from Microsoft's symbol server. This program helps in easily locating the necessary symbol files for debugging and troubleshooting.

### Key Features
- Generates the URL for the debug symbol file from Microsoft's symbol server based on the file's GUID and other information
- Supports both Unicode and ANSI modes

### Usage
1. Clone the repository or download it as a ZIP file.
2. Open the solution file in Visual Studio.
3. Build and run the project.
4. Execute the program from the command line with the path of the file you want to find the symbol for as an argument.

```cmd
SymbolUrlGen.exe <file path>
