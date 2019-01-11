class Solution
{
public:
	string simplifyPath(string path)
	{
		std::vector<string> dirs;
		string result;
		std::string::size_type pos1,pos2;
		pos1=0;
		pos2=path.find("/");
		string str;
		//cout << pos2;
		while(string::npos!=pos2){
			str = path.substr(pos1,pos2-pos1);
			//cout << "pos:"<<pos2;
			//cout <<"str" <<"---------"<<endl;
			
            {
                if(str==""||str==".")
			{
				pos1= pos2 +1;
				pos2 = path.find("/",pos1);
				continue;
			}
			if(str==".."&&!dirs.empty())
				dirs.pop_back();
			else if(str!="..")
				dirs.push_back(str);
            }
			pos1= pos2 +1;
			pos2 = path.find("/",pos1);
		}
		if(pos1!=path.length())
        {
            str = path.substr(pos1);
            if(str==""||str==".")
			{
			}
			else if(str==".."&&!dirs.empty())
				dirs.pop_back();
			else if(str!="..")
				dirs.push_back(str);
        }
			
		if(dirs.empty())
			return "/";
		for(int i=0;i<dirs.size();i++)
			result=result+"/"+dirs[i];
		return result;
	}
	
};