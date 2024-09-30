#include <stdio.h>
#include <type_traits>

// char型以外の引数に対応したMin関数
template<typename T1, typename T2> 
typename std::enable_if<!std::is_same<T1, char>::value && !std::is_same<T2, char>::value, T1>::type
Min(T1 a, T2 b) { 
	return (a < b) ? a : b;
}

// char型が引数に渡された場合にエラーメッセージを出力する特殊化
template<typename T1, typename T2> 
typename std::enable_if<std::is_same<T1, char>::value || std::is_same<T2, char>::value, void>::type 
Min(T1 a, T2 b) { 
	printf("数字以外は代入できません\n"); 
}

int main() {
	int intNum1 = 10, intNum2 = 20;

	float floatNum1 = 15.0f, floatNum2 = 22.5f;

	double doubleNum1 = 5.56, doubleNum2 = 3.45;

	char char1 = 'a', char2 = 'b';

	printf("%d\n", Min(intNum1, intNum2));
	printf("%f\n", Min(floatNum1, floatNum2));
	printf("%lf\n", Min(doubleNum1, doubleNum2));
	
	Min(char1, char2);

	return 0;
}