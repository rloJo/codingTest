using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
  int num;
  float avg = 0;
	
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
		for(int i=0; i<10; i++)
        {
            cin  >> num;
            avg += num;
        }
			cout.setf(ios::fixed);
      cout.precision(0);
      cout << "#" << test_case << " " << avg/10 << "\n"; 
      avg = 0;
	}
	return 0;
}
