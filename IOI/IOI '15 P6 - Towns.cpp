#include <bits/stdc++.h>
using namespace std;
int dst0[110], dstu[110], dstb[110];
inline bool sgroup(int a, int b){
	return !(dstb[a]+dstb[b]==getDistance(a,b));
}
int maxgroup(vector<int> & nodes){
	vector<int> winners[2], losers, wcount[2], lcount;
	for(int i: nodes){
		winners[0].push_back(i);
		wcount[0].push_back(1);
	}
	int curr = 1, pv = 0;
	while(winners[pv].size()>1){
		winners[curr].clear();
		wcount[curr].clear();
		int mx = winners[pv].size()-(winners[pv].size()%2);
		for(int i=0; i<mx; i+=2){
			if(sgroup(winners[pv][i], winners[pv][i+1])){
				winners[curr].push_back(winners[pv][i]);
				wcount[curr].push_back(wcount[pv][i]+wcount[pv][i+1]);
			}
			else{
				losers.push_back(winners[pv][i]);
				losers.push_back(winners[pv][i+1]);
				if(wcount[pv][i+1]>wcount[pv][i]){
					lcount.push_back(wcount[pv][i]);
					lcount.push_back(wcount[pv][i]);
					winners[curr].push_back(winners[pv][i+1]);
					wcount[curr].push_back(wcount[pv][i+1]-wcount[pv][i]);
				}
				else if(wcount[pv][i]>wcount[pv][i+1]){
					lcount.push_back(wcount[pv][i+1]);
					lcount.push_back(wcount[pv][i+1]);
					winners[curr].push_back(winners[pv][i]);
					wcount[curr].push_back(wcount[pv][i]-wcount[pv][i+1]);
				}
				else{
					lcount.push_back(wcount[pv][i]);
					lcount.push_back(wcount[pv][i+1]);
				}
			}
		}
		if(winners[pv].size()%2){
			winners[curr].push_back(winners[pv][winners[pv].size()-1]);
			wcount[curr].push_back(wcount[pv][wcount[pv].size()-1]);
		}
		pv = curr;
		curr = (curr+1)%2;
	}
	if (winners[pv].size()){
		int tt = wcount[pv][0];
		for(int i=0; i<losers.size(); i++){
			if(sgroup(losers[i], winners[pv][0])){
				tt+=lcount[i];
			}
		}
		return tt;
	}
	else{
		return 0;
	}
}
int hubDistance(int N, int sub){
	int da = 0, db = 0, mx = 0;
	memset(dst0, 0, sizeof(dst0));
	memset(dstu, 0, sizeof(dstu));
	memset(dstb, 0, sizeof(dstb));
	for(int i=1; i<N; i++){
		int tp = getDistance(0, i);
		dst0[i]=tp;
		if (tp>mx){
			da = i;
			mx = tp;
		}
	}
	int d = mx;
	dstu[0]=mx;
	for(int i=1; i<N; i++){
		if (i==da){ continue; }
		int tp = getDistance(da, i);
		dstu[i]=tp;
		if (tp>=d){
			db = i;
			d = tp;
		}
	}
	int hd1=1000000000, hd2=1000000000;
	int nh1=0, nh2=0;
	vector<int> hn1, hn2, hnn;
	for(int i=0; i<N; i++){
		dstb[i] = (dstu[i]+dst0[i]-dstu[0])/2;
		int dtu = (dstu[0]+dstu[i]-dst0[i])/2;
		if (dtu>dstu[db]-dtu){
			hd1 = min(hd1, dtu);
			hn1.push_back(i);
		}
		else{
			hd2 = min(hd2, dstu[db]-dtu);
			hn2.push_back(i);
		}
	}
	if (hd1==hd2){
		if (hn1.size()==hn2.size()) return hd1;
		else{
			int tp;
			if (hn1.size()>hn2.size()){
				for(int i: hn1){
					int dtu = (dstu[0]+dstu[i]-dst0[i])/2;
					if (dtu==hd1) hnn.push_back(i);
				}
				if (hn1.size()-hnn.size()>N/2) return -hd1;
				else if (hnn.size()<N/2) return hd1;
			}
			else{
				for(int i: hn2){
					int dtu = (dstu[0]+dstu[i]-dst0[i])/2;
					if (dstu[db]-dtu==hd1) hnn.push_back(i);
				}
				if (hn2.size()-hnn.size()>N/2) return -hd1;
				else if (hnn.size()<N/2) return hd1;
			}
			tp = maxgroup(hnn);
			if (tp>N/2) return -hd1;
			else return hd1;
		}
	}
	else {
		int cnt1=0, cnt2=0;
		int hdf;
		if (hd1<hd2) hdf = hd1;
		else hdf = dstu[db]-hd2;
		int r = max(hdf, dstu[db]-hdf);
		for(int i=0; i<N; i++){
			int dtu = (dstu[0]+dstu[i]-dst0[i])/2;
			if (dtu==hdf){
				hnn.push_back(i);
			}
			else if (dtu>dstu[db]-dtu){
				cnt1++;
			}
			else{
				cnt2++;
			}
		}
		if (cnt1>N/2 || cnt2>N/2) return -r;
		else if ((cnt1+cnt2)*2>=N) return r;
		else{
			int tp = maxgroup(hnn);
			if(tp>N/2) return -r;
			else return r;
		}
	}
}