#pragma once

template <typename T1, typename T2>
class Compare {
public:
	Compare(T1 a, T2 b) : value1_(a), value2_(b) {}

	// 2‚Â‚Ì’l‚ğ”äŠr‚µ‚ÄA¬‚³‚¢•û‚ğ•Ô‚·
	auto Min();

private:
	T1 value1_;
	T2 value2_;
};

template<typename T1, typename T2> inline auto Compare<T1, T2>::Min() { 
	return (value1_ < value2_) ? value1_ : value2_; 
}
