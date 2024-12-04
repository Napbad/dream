# Dap Language Dev  First Step

This is the first step to develop Dap language.

Before you start, you should install the following tools:
**bison**, **flex**, **gcc**, **cmake**, gdb(if you want to debug the compiler and you are using vscode or fleet without bundled gdb like clion);

this is based on linux, you can use wsl on windows, or docker to run linux in windows, the same to Macos.

## 1. Install utils
```bash
sudo apt update 
sudo apt install -y flex bison gcc cmake gdb llvm clang libclang-dev git ninja-build
```

or 

```bash
sudo yum update 
sudo yum install -y flex bison gcc cmake gdb llvm clang clang-devel git ninja-build
```

## 2. Clone the repository

```bash
git clone https://github.com/Napbad/dap.git
cd dap
```

## 3. Try to build the project for the first time
```bash
chmod +x ./compile
./compile
cd build
```
now the compiler is built, you can run it with `./dap_main -h` to see what happends.

you can use `./dap_main ../dap-test/first-step-test.dap -o ./first-step  && ./main` to run the test program
