## Project Name: **Overloaded-Classes-by_Tanner_Davison**

### Description
**Overloeaded-Classes** is a C++ project that demonstrates object-oriented programming concepts such as dynamic memory management, copy constructors, assignment operators, and the creation of custom data structures like an `ArrayList`. The `ArrayList` class manages a dynamically allocated array of characters, providing basic operations such as printing the list and copying data between instances.

### Features
- **Dynamic Memory Management**: The `ArrayList` class dynamically allocates memory for an array of characters and ensures proper memory management with destructors.
- **Copy Constructor**: Safely creates a copy of an `ArrayList` object, duplicating the contents of the original list.
- **Copy Assignment Operator**: Handles assigning one `ArrayList` object to another, ensuring deep copying of the array contents.
- **List Printing**: A method to print the contents of the list to the console.

### Example Usage

1. **Create an `ArrayList` Instance**:
    ```cpp
    ArrayList myList(10); // Create an ArrayList with a length of 10
    ```

2. **Print the List**:
    ```cpp
    myList.printList(); // Outputs the current contents of the list (initially empty/zeroed)
    ```

3. **Copy the `ArrayList` Using the Copy Constructor**:
    ```cpp
    ArrayList copiedList(myList); // Create a new ArrayList as a copy of myList
    copiedList.printList(); // Outputs the copied list contents
    ```

4. **Assign One `ArrayList` to Another**:
    ```cpp
    ArrayList anotherList(5); // Create another ArrayList with a length of 5
    anotherList = myList; // Assign the contents of myList to anotherList
    anotherList.printList(); // Outputs the updated contents of anotherList
    ```

### Compilation and Execution
To compile and run this project, use a C++ compiler such as g++:

```sh
g++ -o entity_arraylist entity_arraylist.cpp
./main
