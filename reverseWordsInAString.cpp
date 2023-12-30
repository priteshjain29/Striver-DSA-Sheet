string reverseWords(string s){
	int n = s.length();
	int end = n-1;
	string ans = "";
	while(end >= 0){
		while(end>=0 and s[end] == ' '){
			end--;
		}
		if(end<0) break;
		if(ans.empty() ==false){
			ans += " ";
		}
		int start = end;

		while(start >= 0 and s[start] != " "){
			start--;
		}

		ans += s.substr(start+1, end-start);
		end = start;
	}
	return ans;
}