class Solution {
	
	bool wordBreak_recurse(string& s, unordered_set<string>& dict, unordered_set<string>& unmatched)
	{
		if (s.length()==0) return true;
		bool flag = false;
		for(int i=1; i<=s.length();i++)
		{
			string str = s.substr(0, i);
			auto ito = dict.find(str);
			if(ito != dict.end())//Find the first word
			{
				string str2 = s.substr(i);
				auto ito2 = unmatched.find(str2);
				if(ito2 != unmatched.end()) continue;//Find this word is in the unmatch set
				else
				{
					flag = wordBreak_recurse(str2, dict, unmatched);
					if(flag) 
					{
						return true;
					}
					else
					{
						unmatched.insert(str2);
					}
				}
			}
		}
		return false;
	}
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if (s.length()==0) return true;
        unordered_set<string> unmatched;
        return wordBreak_recurse( s, dict, unmatched);
    }
};