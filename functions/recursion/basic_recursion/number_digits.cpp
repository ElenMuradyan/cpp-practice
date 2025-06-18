int reverse (int n, int result = 0){
    if(n == 0){
        return result;
    }

    return reverse(n / 10, result * 10 + n % 10);
}

int countDigits (int num) {
    if(num < 10) return 1;

    return 1 + countDigits(num / 10);
}


int sumOfDigits (int num){
    if(num < 10){
        return num;
    }
    return num % 10 + sumOfDigits(num / 10);
}

int countOccurrences (int num, int digit) {
    if(num == 0){
        return 0;
    }
    
    return num % 10 == digit ? 1 + countOccurrences(num / 10, digit) : countOccurrences(num / 10, digit); 
}

int maxDigit (int num){
    if(num < 10){
        return num;
    }

    int maxRest = maxDigit(num / 10);
    int lastDigit = num % 10;

    return (maxRest > lastDigit) ? maxRest : lastDigit;
}

int sumOfDigits2 (int n, const int &sum) {
    if(n == 0) return sum;

    int last = n % 10;
    int num = n / 10;
    return last % 2 ? sumOfDigits2(num, sum) : sumOfDigits2(num, sum + last);
}

int productOfDigits (int n, const int &product) {
    if(n == 0) return product;

    int last = n % 10;
    int num = n / 10;
    return productOfDigits(num, product * last);
}
