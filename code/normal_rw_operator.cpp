typedef vsmc::cxx11::function<double (double)> ftype;
template <typename Eng>
bool operator() (
	double &val, double sd, Eng &eng, const ftype &f);
