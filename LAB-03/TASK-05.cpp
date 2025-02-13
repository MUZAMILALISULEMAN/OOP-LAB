#include<iostream>
using namespace std;
class MusicPlayer{
	private:
		string playlist[100];
		string currentlyPlayingSong;
		int songCount = 0;
	public:
		
		MusicPlayer(){
			
			currentlyPlayingSong = "";
			
			
		}
		void addSong(string song){
			if(songCount < 100){
			cout<<song<<" SONG ADDED TO PLAYLIST"<<endl;
			playlist[songCount++] = song;
				
			}else{
				cout<<endl<<"UNABLE TO ADD!"<<endl;
			}
			
		}
		
		void playSong(string song){
			int k=0;
			for(int i=0;i<songCount;i++){
				if(playlist[i] == song){
					currentlyPlayingSong = song;
					cout<<"PLAYING SONG "<<song<<endl;
					k=1;
					return;
				}
			}
			if(k==0){
				cout<<"CANNOT PLAY SONG, NOT FOUND IN PLAYLIST"<<endl;
			}
		}
	
		void removeSong(string song){
			int k=0;
			for(int i=0;i<songCount;i++){
				if(playlist[i] == song){
						 k =1;
					int start = i;
					for(int j = start;j<songCount;j++){
						playlist[i] = playlist[i+1];
		
					}
					
					
				}
				playlist[songCount] = "";
			}
			if(k ==0){
				cout<<"UNABLE TO REMOVE, NOT FOUND"<<endl;
				return;
			}
			cout<<song<<" REMOVED FROM THE PLAYLIST"<<endl;
			songCount--;
			
		}
		
		void displayPlaylist(){
			cout<<"SONGS: ";
			int k = 0;
			for(int i=0;i<songCount;i++){
				cout<<endl<<i+1<<". "<<playlist[i];
				k=1;
			}
			if(k==0){
				cout<<"SONG NOT FOUND";
			}
			cout<<endl;
			
		}
	
};
int main() {


MusicPlayer playlist;
playlist.addSong("MZ");
playlist.addSong("V");
playlist.playSong("MZ");
playlist.removeSong("MAZ");
playlist.removeSong("MZ");
playlist.removeSong("V");
playlist.displayPlaylist();

	return 0;
}
