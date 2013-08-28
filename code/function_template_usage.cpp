max(1, 2); // Correct, a: int, b: int, deduce T: int
max(1, 2L); // ERROR, a: int, b: long, cannot deduce T
std::complex<double> c1, c2;
max(c1, c2); // ERROR, no operator < defined for std::complex
