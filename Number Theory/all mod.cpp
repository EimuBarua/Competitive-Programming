ll ad(ll x,ll y){ll f=((x%mod)+(y%mod)+mod)%mod;return f;}
ll sub(ll x,ll y){ll f=((x%mod)-(y%mod)+mod)%mod;return f;}
ll mul(ll x,ll y){ll f=((x%mod)*(y%mod)+mod)%mod;return f;}
ll bigmod(ll n,ll m){ll f=1;while(m){if(m%2==1)f=((f%mod)*(n%mod))%mod;n=((n%mod)*(n%mod))%mod;m/=2;}return (f%mod+mod)%mod;}
