int firstUniqChar(char* s) { 
    int count=-1; bool check;
    for(int i=0;i<strlen(s);i++){ 
        check=true;
        for(int j=0;j<strlen(s);j++){ 
            if(i==j){continue;}
            if(s[i]==s[j]){
                check=false;
                break; 
            } 
        }
        if(check){
            return i;
        }
    } 
    return count;
}
