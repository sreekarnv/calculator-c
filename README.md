# Calculator

## Windows Installation

On Windows ensure to install gtk4 from https://github.com/wingtk/gvsbuild.

### Prerequistes

1. [Chocolatey](https://chocolatey.org/)
2. [MSYS](https://www.msys2.org/)
3. [UV](https://docs.astral.sh/uv/)
4. [Visual Studio Build Tools](https://visualstudio.microsoft.com/downloads/?q=build+tools)

#### Install Prerequistes

```bash
# Install MSYS
choco install msys2

# Run cmd (or) powershell -ExecutionPolicy ByPass -c "irm https://astral.sh/uv/install.ps1 | iex"
choco install uv 

# Run cmd (or) download from website - https://visualstudio.microsoft.com/downloads/?q=build+tools
choco install visualstudio2022-workload-vctools 
```

### Install GTK4

```bash
# Clone the Repository and Setup env
git clone https://github.com/wingtk/gvsbuild.git
uv sync

# Install gvsbuild and gtk4
uv tool install gvsbuild 
uv run gvsbuild build gtk4
```

Once installation is done add `C:\gtk-build\gtk\x64\release\bin` to PATH. Check out instructions on how to use this with Visual Studio [here](https://github.com/wingtk/gvsbuild#using-gtk-with-visual-studio).
