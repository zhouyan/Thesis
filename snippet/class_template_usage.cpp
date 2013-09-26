Stack<std::string> sstack;
sstack.push_back("foo");
sstack.push_back("bar");
sstack.pop();
if (!sstack.empty())
    std::cout << sstack.top() << std::endl;
