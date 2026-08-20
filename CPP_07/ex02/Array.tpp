
template <typename T>
Array<T>::Array(void) {
    this->_arr = NULL;
    this->_n = 0;
}

template <typename T>
Array<T>::Array(unsigned int n) {
    this->_arr = new T[n];
    this->_n = n;
}

template <typename T>
Array<T>::~Array(void) {
    std::cout << "Destructor has been called" << std::endl;
}

template <typename T>
Array<T>::Array(const Array<T>& copy) : _n(copy._n) {
    // this->_arr = new T[copy._n];
    for (unsigned int i = 0; i < copy.size(); i++)
        this->_arr[i] = copy._arr[i];
    // *(this->_arr) = *copy._arr;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& copy) {
    if (*this != copy) {
        delete this->_arr;
        this->_arr = new T[copy.size()];
        *(this->_arr) = *copy._arr;
    }
    return (*this);
}

template <typename T>
std::ostream &operator<<(std::ostream &oss, const Array<T>& ref) {
    T* ptr = ref.getArr();
    for (unsigned int i = 0; i < ref.size(); i++)
        oss << *(ptr + i) << " ";
    return (oss);
}

template <typename T>
T& Array<T>::operator[](unsigned int n) const {
    if (n <= 0 || n >= _n)
        throw (NumOutOfBound());
    return (_arr[n]);
}