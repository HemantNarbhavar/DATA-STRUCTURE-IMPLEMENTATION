// -------------------- Set Structure -------------------------
typedef struct Set
{
    int size;
    int a[20000];
    int prev[20000];
    int next[20000];
}Set;

typedef struct searchResult
{
    int found;
    int val;
}SearchResult;

// -------------------- Set Methods -------------------------------
Set buildSet(int a[], int n); // done
int len(Set s); // done

Set put(int x, Set s); // done
Set rmv(int x, Set s); // done

int isEmptySet(Set s); // done
SearchResult search(int x, Set s); // done 

SearchResult prev(int x, Set s); // done
SearchResult next(int x, Set s); // done
SearchResult first(Set s); // done
SearchResult last(Set s); // done

// ------------------- Internal Methods ---------------------------

Set _buildEmptySet(); // done
Set store_next(int n, Set s); // done
Set store_prev(int n, Set s); // done

// ------------------ Method Imlementation --------------------------

Set buildSet(int a[], int n)
{
    Set s = _buildEmptySet();
    SearchResult r;
    for(int i=0; i<n; i++)
        s = put(a[i],s);
    s = store_next(n,s);
    s = store_prev(n,s);
    return s;
}

Set _buildEmptySet()
{
    Set s;
    for(int i=0; i<20000; i++)
    {
        s.a[i] = 0;
        s.prev[i] = 0;
        s.next[i] = 0;
    }
    s.size = 0;
    return s;
}

int isEmptySet(Set s)
{
    int x = 1;
    for(int i=0; i<20000; i++)
    {
        if(s.a[i] == 1)
            x = 0;
    }
    return x;
}

int len(Set s)
{
    return s.size;
}

Set put(int x, Set s)
{
    SearchResult r = search(x,s);
    if(r.found == 0)
    {
        s.a[x+10000] = 1;
        s.size += 1;
    }
    return s;
}

SearchResult first(Set s)
{
    SearchResult r;
    int x = isEmptySet(s);
    if(x == 0)
    {
        for(int i=0; i<20000; i++)
        {
            if(s.a[i] == 1)
            {
                r.found = 1;
                r.val = i-10000;
                break;
            }
        }
    }
    return r;
}

SearchResult last(Set s)
{
    SearchResult r;
    int x = isEmptySet(s);
    if(x == 0)
    {
        for(int i=20000; i>0; i--)
        {
            if(s.a[i] == 1)
            {
                r.found = 1;
                r.val = i-10000;
                break;
            }
        }
    }
    return r;
}

SearchResult search(int x, Set s)
{
    SearchResult r;
    r.found = 0;
    if(s.a[x+10000] == 1)
    {
        r.found = 1;
        r.val = x;
    }
    return r;
}

Set rmv(int x, Set s)
{
    SearchResult r = search(x,s);
    if(r.found != 0)
    {
        SearchResult f = first(s);
        SearchResult l = last(s);
        if(f.val == x)
        {
            SearchResult ele = next(x,s);
            s.a[x+10000] = 0;
            s.prev[x+10000] = 0;
            s.next[x+10000] = 0;
            s.prev[ele.val+10000] = ele.val;
        }
        else if(l.val == x)
        {
            SearchResult ele = prev(x,s);
            s.a[x+10000] = 0;
            s.prev[x+10000] = 0;
            s.next[x+10000] = 0;
            s.next[ele.val+10000] = ele.val;
        }
        else
        {
            SearchResult e1 = next(x,s);
            SearchResult e2 = prev(x,s);
            s.a[x+10000] = 0;
            s.prev[x+10000] = 0;
            s.next[x+10000] = 0;
            s.prev[e1.val+10000] = e2.val;
            s.next[e2.val+10000] = e1.val;
        }
    }
    return s;
}


SearchResult prev(int x, Set s)
{
    SearchResult r = search(x,s);
    if(r.found == 1)
    {
        if(x == s.prev[x+10000])
            r.found = 0;
        else
            r.val = s.prev[x+10000];
    }
    return r;
}

SearchResult next(int x, Set s)
{
    SearchResult r = search(x,s);
    if(r.found == 1)
    {
        if(x == s.next[x+10000])
            r.found = 0;
        else
            r.val = s.next[x+10000];
    }
    return r;
}


Set store_prev(int n, Set s)
{
    int temp;
    int count = n;
    for(int i=0; i<20000; i++)
    {
        if(s.a[i] == 1)
        {
            if(count == n)
            {
                temp = i;
                s.prev[i] = temp-10000;
                
            }
            else
            {
                s.prev[i] = temp-10000; 
                temp = i;
            }
            count--;
        }
    }
    return s;
}

Set store_next(int n, Set s)
{
    int temp;
    int count = n;
    for(int i=20000; i>0; i--)
    {
        if(s.a[i] == 1)
        {
            if(count == n)
            {
                temp = i;
                s.next[i] = temp-10000;
            }
            else
            {
                s.next[i] = temp-10000;
                temp = i;
            }
            count--;
        }
    }
    return s;
}
