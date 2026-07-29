char* longestCommonPrefix(char** strs, int strsSize) {
    char *s,*p;
    int i,k,min=200;
    if(strsSize == 1){
        return *strs;
    }
    for(i=1;i<strsSize;i++){
        s = *strs;
        p = *(strs+i);
        k=0;
        while(*s!=0 && *p!=0 && *s==*p){
            s++;
            p++;
            k++;
        }
        if(k<min)
            min = k;
    }
    char *str = (char*)malloc((min+1)*sizeof(char));
    for(i=0;i<min;i++)
        *(str+i) = *(*(strs)+i);
    *(str+i) = 0;
    return str;
}