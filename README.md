# To compile, follow the these instructions.

>> source set_env.sh
>> mkdir build
>> cd build
>> cmake ..
>> make

# To run the program.

>> cd bin
>> ./helloworld.x

# To create your own project.
#
# 1. Modify PROJECT_NAME from HELLOWORLD to your own project name in set_env.sh
# 2. Write source files (.cpp) in /src, templates (.hpp or .hxx) in /frame.
# 3. Put headers and prototypes (.h or .hpp) in /include.
# 4. Write additional test files (.cpp with main() function) in /test.
# 5. Follow the 5 instructions above to compile.
