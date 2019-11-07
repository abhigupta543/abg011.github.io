int modulo(string &x, int A){
    //cout << x << endl;
    int divident = 0;
    int divisor = A;
    int reminder = 0;
    int quotient = 0;
    int index = 0;
    while(index < x.size()){
        divident = divident*10 + (x[index]-'0');
        if(divident<divisor){
            reminder = divident;
            index++;
            continue;
        }
        else{
            reminder = divident%divisor;
            //cout << divident << " " <<reminder << endl;
            divident = reminder;
            index++;
        }
    }
    return reminder;
}

string Solution::multiple(int A) {
    string ans = "1";
    queue<string> q;
    q.push(ans);
    while(1){
        string temp = q.front();
        q.pop();
        if(modulo(temp, A) == 0){
            return temp;
        }
        else{
            q.push(temp+'0');
            q.push(temp+'1');
        }
    }
}
