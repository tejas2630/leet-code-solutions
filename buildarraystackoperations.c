char** buildArray(int* target, int targetSize, int n, int* returnSize) {
    char** ret = calloc(3 * targetSize, sizeof(char*));
    const char *push = "Push", *pop = "Pop";
    *returnSize = 0;
    int idx = 1, cur = 0;
    
    while (cur < targetSize){
        ret[(*returnSize)++] = push;
        
        if (idx != target[cur])
            ret[(*returnSize)++] = pop;
        else
            cur++;
                
        idx++;
        }return ret;}
