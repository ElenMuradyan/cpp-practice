#include <iostream>
#include <string>

using namespace std;

class Timer {
    private:
        int seconds;
        int minutes;
        int hours;

        void normalize(){
            if(seconds >= 60){
                minutes += seconds / 60;
                seconds %= 60;
            }

            if(minutes >= 60){
                hours += minutes / 60;
                minutes %= 60;
            }

            if(hours >= 24){
                hours %= 24;
            }
        }
    public:
        Timer(int hours, int minutes, int seconds): seconds(seconds), minutes(minutes), hours(hours){normalize();}
        void increaseSeconds(int s){
            seconds += s;
            normalize();
        }

        void increaseMinutes(int m){
            minutes += m;
            normalize();
        }

        void increaseHours(int h){
            hours += h;
            normalize();
        }

        friend ostream &operator<<(ostream &out, const Timer &t){
            string hours = t.hours < 10 ? "0" + to_string(t.hours) : to_string(t.hours);
            string mins = t.minutes < 10 ? "0" + to_string(t.minutes) : to_string(t.minutes);
            string seconds = t.seconds < 10 ? "0" + to_string(t.seconds) : to_string(t.seconds);

            out << hours << " : " << mins << " : " << seconds;
            return out;
        }
};
