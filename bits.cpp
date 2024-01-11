#include <iostream>

// Function to check if the k-th bit is set in x
bool isKthBitSet(int x, int k) {
    return (x >> k) & 1;
}

// Function to set the k-th bit in x
int setKthBit(int x, int k) {
    return x | (1 << k);
}

// Function to unset the k-th bit in x
int unsetKthBit(int x, int k) {
    return x & (~(1 << k));
}

// Function to toggle the k-th bit in x
int toggleKthBit(int x, int k) {
    return x ^ (1 << k);
}

// Function to count the number of set bits (1s) in x
int countSetBits(int x) {
    int count = 0;
    while (x) {
        count += x & 1;
        x >>= 1;
    }
    return count;
}

// Function to print the binary representation of x
void printBinary(int x) {
    for (int i = 31; i >= 0; --i) {
        std::cout << ((x >> i) & 1);
    }
    std::cout << '\n';
}

int main() {
    // Example usage
    int num = 17; // Binary representation: 10001

    // Check if the 3rd bit is set in num
    std::cout << "Bit at position 3 is " << (isKthBitSet(num, 3) ? "set" : "unset") << '\n';

    // Set the 2nd bit in num
    int numWithSetBit = setKthBit(num, 2);
    std::cout << "After setting bit at position 2: ";
    printBinary(numWithSetBit);

    // Unset the 4th bit in num
    int numWithUnsetBit = unsetKthBit(num, 4);
    std::cout << "After unsetting bit at position 4: ";
    printBinary(numWithUnsetBit);

    // Toggle the 1st bit in num
    int numWithToggledBit = toggleKthBit(num, 1);
    std::cout << "After toggling bit at position 1: ";
    printBinary(numWithToggledBit);

    // Count the number of set bits in num
    std::cout << "Number of set bits in " << num << ": " << countSetBits(num) << '\n';

    return 0;
}
