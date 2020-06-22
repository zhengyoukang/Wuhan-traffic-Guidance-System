#include<iostream>
#include<stdlib.h>
#include<limits.h>
#define MaxSize 30
#define LinessNum 13
using namespace std; 
//���ÿ��վ��Ϣ 
struct {
	int number;//վ���� 
	string name;//վ������ 
	int sidenum;//����վ������ 
	int side[MaxSize];//����վ���� 
	int belong[MaxSize];//������Щ��· 
	int benum; //���ڵ���·���� 
}Station[32]={{1,"����",1,{3},{},0},{2,"����վ",1,{4},{},0},{3,"����·",4,{1,4,5,11},{},0},{4,"����·",3,{2,3,7},{},0},{5,"����·",3,{3,6,7},{},0},{6,"�人��",1,{5},{},0},{7,"��ʤ·",3,{4,5,8},{},0},{8,"��̨",4,{9,10,17,7},{},0},{9,"����԰",1,{8},{},0},{10,"��Ԫ��",1,{8},{},0},
			{11,"���Ҿ�",3,{3,12,15},{},0},{12,"����",3,{11,14,13},{},0},{13,"��ɽ",2,{12,23},{},0},{14,"���",4,{12,15,20,21},{},0},{15,"��ɽ�㳡",4,{11,14,16,19},{},0},{16,"������",2,{15,18},{},0},{17,"�ƺ�¥",2,{8,18},{},0},{18,"����",4,{16,17,19,25},{},0},{19,"����·",3,{15,18,20},{},0},{20,"�ֵ���",4,{14,19,21,26},{},0},
			{21,"׿��Ȫ",4,{14,20,22,27},{},0},{22,"��Ժ",2,{21,23},{},0},{23,"³��",3,{13,22,24},{},0},{24,"���пƴ�",2,{23,30},{},0},{25,"���վ",3,{18,26,29},{},0},{26,"�人����",4,{20,25,27,29},{},0},{27,"����Ժ",3,{21,26,28},{},0},{28,"�人��Ժ",2,{27,30},{},0},{29,"����ũ��",2,{25,26},{},0},{30,"��ɽ",2,{24,28}},{},0}; 
struct {
	int which;//������· 
	int nunbers;//��·��������վ 
	int Stas[MaxSize]; //������վ���� 
}Liness[MaxSize]={{1,7,{2,4,7,8,17,18,25}},{2,5,{2,4,7,5,6}},{3,13,{2,4,7,8,17,18,19,20,21,22,23,24,30}},{4,3,{1,3,4}},
				{5,9,{4,7,8,17,18,19,15,11,3}},{6,5,{9,8,7,5,3}},{7,8,{10,8,17,18,16,15,14,12}},{8,5,{4,3,11,12,13}},{9,5,{25,26,27,28,30}},{10,4,{29,26,20,14}},
				{11,5,{29,25,18,17,8}},{12,5,{30,24,23,13,12}},{13,11,{6,5,3,11,15,19,20,21,27,28,30}}};
//��ͨ��Ϣ
typedef struct{
	int n;
	int Sta[MaxSize][MaxSize];//����վ����ͨ��� 
}Route;
//����վ��Ĺ�����·
void CreatRold(Route *&a){
	for(int i=1;i<=LinessNum;i++){
		for(int j=1;j<=Liness[i-1].nunbers;j++){
			int a=Liness[i-1].Stas[j-1];//��i����·�ĵ�j��վ�� 
			int b=Liness[i-1].which;//������·�ı�� 
			Station[a-1].belong[Station[a-1].benum++]=b;//benum������Զ��������·����һ 
		}
	}
} 
//����վ��Ĺ�������
void CreatArray(Route *&a){
	int i,j,k=0,flag=0;
	for(i=0;i<a->n;i++){
		for(j=0;j<a->n;j++){
			if(i==j)
				a->Sta[i][j]=0;
			else
				a->Sta[i][j]=INT_MAX;
		}
	}
	for(i=0;i<a->n;i++){
		for(k=0;k<Station[i].sidenum;k++) {
			int buf=Station[i].side[k]-1;
			a->Sta[i][Station[i].side[k]-1]=1;
		}
	}
} 
//��ʼ������ 
void InitData(Route *&a,int v){
	a=(Route *)malloc(sizeof(Route));
	int i,j;
	a->n=v;
}
//������ʼ·������
void InitArray(int RodeArray[],int now,int &max,int witch,int endlist[][MaxSize],int indexnow){
	int i,j,k;
	int bufnow=now;
	int init=endlist[witch][now];
	if(now==indexnow){
		int hind=endlist[witch][now-1];
		for(int m=0;m<Station[init].benum;m++){
			for(int n=0;n<Station[hind].benum;n++){
				int fromSta=Station[init].belong[m];
				int toSta=Station[hind].belong[n];
				if(fromSta==toSta){
					RodeArray[max++]=toSta;//max��������ɻ�����·����� 
				}
			}	
		}	
	//���RodeArray����
	cout<<Station[init].number<<"."<<Station[init].name;
		cout<<"(�ɳ�����";		
	for(i=0;i<max;i++){
	cout<<RodeArray[i];
		if(i!=max-1)
			cout<<"��";
	} 
	cout<<"·����)";
	if(now!=0)
		cout<<" ==> ";
	else
		cout<<endl;
	cout<<Station[hind].number<<"."<<Station[hind].name<<"(�ɳ�����";
		for(i=0;i<max;i++){
			cout<<RodeArray[i];
			if(i!=max-1)
				cout<<"��";
		} 
		cout<<"·����)";
	if(now!=1)
		cout<<" ==> ";
	else
		cout<<endl;
	}else{
		int hind=endlist[witch][now+1];
		for(int m=0;m<Station[init].benum;m++){
			for(int n=0;n<Station[hind].benum;n++){
				int fromSta=Station[init].belong[m];
				int toSta=Station[hind].belong[n];
				if(fromSta==toSta){
					RodeArray[max++]=toSta;//max��������ɻ�����·����� 
				}
			}	
		}
		cout<<Station[init].number<<"."<<Station[init].name<<"(�ɻ��ˣ�";
		for(i=0;i<max;i++){
			cout<<RodeArray[i];
			if(i!=max-1)
				cout<<"��";
		}
		cout<<"·����)";
		if(now!=0)
			cout<<" ==> ";
		else
			cout<<endl; 
	}
} 
//����RodeArray����
void Reflash(int RodeArray[],int &max,int buffRode[],int maxbuff,int now,int witch,int indexnow){
	max=maxbuff;int i; 
	for(i=0;i<=maxbuff;i++){
		RodeArray[i]=buffRode[i];
	}
	cout<<Station[witch].number<<"."<<Station[witch].name<<"(�ɳ�����";
		for(i=0;i<=max;i++){
			cout<<RodeArray[i];
			if(i!=max)
				cout<<"��";
		}
		cout<<"·����)";
	if(now!=0)
		cout<<" ==> ";
	else
		cout<<endl;
} 
//�������·����Ҫ���˵Ĵ���
void ChaTime(int endlist[][MaxSize],int ansnum,int now,int Times[]){
	int i,j,m,n;
	for(i=0;i<=ansnum;i++){
		Times[i]=0;
	}
	cout<<endl<<"����"<<ansnum+1<<"����·����ѡ��"<<endl;
	for(i=0;i<=ansnum;i++){
		cout<<endl<<"��"<<i+1<<"����·��"<<endl<<"~~~";
		int max=0,RodeArray[MaxSize],buffRode[MaxSize];
		InitArray(RodeArray,now,max,i,endlist,now);
		if(now>=2){
			for(j=now-2;j>=0;--j){
				int flag=0,init=endlist[i][j],maxbuff=-1;
				for(int m=0;m<=max;m++){
					for(int n=0;n<Station[init].benum;n++){					
						int toSta=Station[init].belong[n];
						if(RodeArray[m]==toSta){
							flag=1;
							buffRode[++maxbuff]=RodeArray[m];				
						}
					}	
				}
				if(flag==0){
					max=0;
					Times[i]++;					 
					InitArray(RodeArray,j,max,i,endlist,now);
				}else if(flag==1){
					flag=0;
					Reflash(RodeArray,max,buffRode,maxbuff,j,endlist[i][j],now);
				}
			}
		}
	}
} 
//����·��,��С���� 
void SortTimes(int Times[],int init,int ansnum,int Deal[]){
	if(ansnum<=init)
		return;
	int i=init,j=ansnum,base=Times[init],baseD=Deal[init],temp;
	while(i<j){
		while(Times[j]>=base&&i<j)
			j--;
		while(Times[i]<=base&&i<j)
			i++;
		if(i<j){
			temp=Times[i];
			Times[i]=Times[j];
			Times[j]=temp;
			temp=Deal[i];
			Deal[i]=Deal[j];
			Deal[j]=temp;
		}
	}
	Times[init]=Times[i];
	Times[i]=base;
	Deal[init]=Deal[i];
	Deal[i]=baseD;
	SortTimes(Times,init,i-1,Deal);
	SortTimes(Times,i+1,ansnum,Deal);
}
//��ӡ·��
void Showrode(int ansnum,int endlist[][MaxSize],int now,int to){
	int i,j;
	int Times[MaxSize];//��¼ÿһ����·���˴�����
	int Deal[MaxSize]; //���˴������� 
	for(i=0;i<=ansnum;i++){
		Deal[i]=i;
	}	
	ChaTime(endlist,ansnum,now,Times);//����ÿ��·�����˴�������Timesһά������ 
	SortTimes(Times,0,ansnum,Deal);//�Ӵ�С����Deal���·���±� 
	cout<<endl; 
	for(j=0;j<=ansnum;j++){ 
		for(i=now;i>=0;i--){
			int buff=endlist[Deal[j]][i]+1;
			cout<<buff<<" ";//���������õ������±� 
		}
		
		cout<<"�����ˣ�"<<Times[j]<<"��"<<endl;
	}
}
//����ǰ�������Ԫ��
void CopyList(int endlist[][MaxSize],int ansnum,int now){
		for(int i=0;i<=now;i++){
			endlist[ansnum][i]=endlist[ansnum-1][i];
		}
} 
//���·������                      0            end      v   0
void Getrode(int endlist[][MaxSize],int now,int from,int to,int ansnum,int path[][MaxSize],int s[],int anser[2],int init){
	int i;
	anser[0]=max(anser[0],ansnum);
	anser[1]=max(anser[1],now);
	/**/if(from!=0){
		endlist[ansnum][now]=from;
	}else{
		if(init==0)
			endlist[ansnum][now]=from;
		else
			anser[1]=now-1;
	}
	for(i=0;i<s[from];i++){	
		if(from!=0){
			int bufnow=now;
			if(i>=1){
				int bufans=ansnum+1;
				CopyList(endlist,bufans,now);
				ansnum++;
			}
			if(from!=0)
			Getrode(endlist,++bufnow,path[from][i],to,ansnum,path,s,anser,init);
		}
	}
} 
//�õ����·��         ·��          վ��ǰ׺�� վ����   ���  
Dispath(int dist[],int path[][MaxSize],int s[],int n,int v,int t){
	int endlist[MaxSize][MaxSize],ansnum=0;
	int now=0;
	int anser[2]={0,0};//[0]����ansnum��[1]���� new
	Getrode(endlist,now,t,v,ansnum,path,s,anser,v);//��ö���·�� ���Զ�ά������ 	
	Showrode(anser[0],endlist,anser[1],t);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              

}
//Dijkstra�㷨
void Dijkstra(Route *g,int v,int t){
	int s[MaxSize],dist[MaxSize],path[MaxSize][MaxSize];
	int i,j,u,mindis,num[MaxSize];
	for(i=0;i<g->n;i++){
		dist[i]=g->Sta[v][i];
		num[i]=1;
		s[i]=0;
		if(g->Sta[v][i]<INT_MAX){
			path[i][0]=v;
		}else{
			path[i][0]=-1;
		}
	}
	s[v]=1;path[v][0]=0;
	for(i=0;i<g->n;i++){
		mindis=INT_MAX;
		for(j=0;j<g->n;j++){
			if(s[j]==0&&dist[j]<mindis){
				u=j;
				mindis=dist[j];	
			}
		}
		s[u]=1;
		for(j=0;j<g->n;j++){
			if(s[j]==0){
				if(g->Sta[u][j]<INT_MAX&&dist[u]+g->Sta[u][j]<dist[j]){
					dist[j]=dist[u]+g->Sta[u][j];
					num[j]=1;
					path[j][0]=u;	
				}
				else if(g->Sta[u][j]<INT_MAX&&dist[u]+g->Sta[u][j]==dist[j]){
					num[j]++;
					path[j][num[j]-1]=u;
				}
			}
		}
	}	
	Dispath(dist,path,num,g->n,v,t);
} 
//��ӡ��ͼ
void ShowMap(){
cout<<"�人�н�ͨ��ͼ:"<<endl<<endl; 
cout<<"\t"<<"           * 6(�人��)                                                        "<<endl;
cout<<"\t"<<"           |                                                                  "<<endl;
cout<<"\t"<<"           |                                                                  "<<endl;
cout<<"\t"<<"           * 5(����·)                                                        "<<endl;
cout<<"\t"<<"           |	                                                               "<<endl;
cout<<"\t"<<"1(����)    |3(����·) 11(���Ҿ�) 12(����)  13(��ɽ)  23(³��)  24(���пƴ�)   "<<endl;
cout<<"\t"<<"*----------*----------*----------*-------- *--------- *-------- *             "<<endl;
cout<<"\t"<<"           |	      |(��ɽ�㳡)|		      |         |                      "<<endl;
cout<<"\t"<<"2(����վ)  |          | 15 	 |(���)   21(׿��Ȫ) | (��Ժ)  |              "<<endl;
cout<<"\t"<<"*----------* 4(����·)*----------* 14--...  *-------- * 22    * 30(��ɽ)      "<<endl;
cout<<"\t"<<"           |	      | ` ------,	 `-.|                   |              "<<endl;
cout<<"\t"<<"           |7(��ʤ·)|16(������)/19(����·) | 20(�ֵ���)        |             "<<endl;
cout<<"\t"<<"           *          *-------- *-----------*                   * 28(�人��Ժ)"<<endl;
cout<<"\t"<<"           |          |		            |(�人����)       |              "<<endl;
cout<<"\t"<<"9(����԰)  | 8(��̨)	------18(����)    | 26        ,-------`              "<<endl;
cout<<"\t"<<"*----------*-------- *-------- *------------* ---------* 27(����Ժ)           "<<endl;
cout<<"\t"<<"           |        17(�ƺ�¥) |  __________|                                 "<<endl;
cout<<"\t"<<"           |	               | /                                             "<<endl;
cout<<"\t"<<"           * 10(��Ԫ��)        * 25(���վ)                                   "<<endl;
cout<<"\t"<<"		               |                                                       "<<endl;
cout<<"\t"<<"		               |                                                 	   "<<endl;
cout<<"\t"<<"		               * 29 (����ũ��)                                		   "<<endl;
cout<<endl;
} 
//�û�����
void UserGet(int &from,int &to){
	int i,j;
	cout<<"���������վ��:";
	cin>>from;
	if(from<1||from>MaxSize){
		cout<<"����������"; 
		exit(0);
	}
	cout<<"�������յ�վ��:";
	cin>>to;
	if(to<1||to>MaxSize){
		cout<<"�յ��������"; 
		exit(0);
	}	
	cout<<endl<<"���ĳ������ǣ�"<<Station[from-1].name<<"     ";
	cout<<"��Ҫȥ�ĵط��ǣ�"<<Station[to-1].name<<endl;;
}  
int main()
{
	int num=30;
	Route *a;
	InitData(a,num);
	CreatArray(a);//������ά���� 
	CreatRold(a);//������·�� 
	ShowMap(); 
	int from=-1,to=-1;//�����±��ʾ 
	UserGet(from,to);
	Dijkstra(a,from-1,to-1); //��ò���ӡ���·�� 	
	return 0;
}
