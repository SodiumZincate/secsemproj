#include <iostream>
#include <vector>
// #include requisite/qt/include/QtWidgets/QWidget> // For QString in case you are using Qt

int main() {
    // Initialize an empty vector
    std::vector<std::string> myList;

    // Define a lambda function that captures the vector by reference
    auto addToList = [&myList]() {
        // Add some items to the vector
        myList.push_back("Item 1");
        myList.push_back("Item 2");
    };

    // Call the lambda function
    addToList();

    // Print the contents of the vector to verify the changes
    for (const auto& item : myList) {
        std::cout << item << std::endl;
    }

    return 0;
}