string encode(string s)
{     
  //Your code here 
  string ans="";
  int n=s.length();
  for(int i=0;i<n;i++){
      int j=i;
      while(j<n){
          if(s[j]!=s[i]){
              break;
          }
          j++;
      }
      ans+=s[i];
      ans+=(char)(j-i+'0');
      i=j-1;
  }
  return ans;
  
}     
