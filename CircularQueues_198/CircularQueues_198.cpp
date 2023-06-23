#include <iostream>
using namespace std;

class queues {
	int FRONT, REAR, max = 5;
	int queue_array[5];

public:
	queues() {
		FRONT = -1;
		REAR = -1;
	}

	void insert() {
		int num;
		cout << "Enter a number : ";
		cin >> num; 
		cout << endl;

		//cek bila antrian penuh
		if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)) {
			cout << "\nqueues overflow\n";
			return;
		}

		//cek pakah antrian kosong
		if (FRONT == -1) {
			FRONT = 0;
			REAR = 0;
		}
		else {
			//jika REAR berada diposisi terakhir array, kembali ke awal array
			if (REAR == max - 1)
				REAR = 0;
			else
				REAR = REAR + 1;
		}
		queue_array(REAR) = num;
	}

	void remove() {
		//cek apakah antrin kosong
		if (FRONT == -1) {
			cout << " Queue underflow\n";
			return;
		}
		cout << "\nThe element delected from the queue is : " << queue_array[FRONT] << "\n";

		//cek jika antrian memiliki satu elemen
		if (FRONT == REAR) {
			FRONT = -1;
			REAR = -1;
		}
		else {
			//jika elemen dihapus berada di posisi terakhir array, kembali ke awal array
			if (FRONT == max - 1)
				FRONT = 0;
			else
				FRONT = FRONT + 1;
		}
	}

	void display() {
		int FRONT_position = FRONT;
		int REAR_position = REAR;

		//cek apakah antrian kposong
		if (FRONT == -1) {
			cout << " Queue is empty\n ";
			return;
		}

		cout << "\nElemen is the queue are...\n";

		//jika FRON position <= REAR_position. interasi FRONT hingga REAR
		if (FRONT_position <= REAR_position) {
			while (FRONT_position <= REAR_position) {
				cout << queue_array[FRONT_position] << "  ";
				FRONT_position++;
			}
			cout << endl;
		}
		else {
			//jika FRONT_position > REAR_position, interaksi dari FRONT hingga array
			while (FRONT_position <= n - 1) {
				cout << queue_array[FRONT_position] << "  ";
				FRONT_position++;
			}

			FRONT_position = 0;
			//interasi dari awal array hingga REAR
			while (FRONT_position <= REAR_position) {
				cout << queue_array[FRONT_position] << "  ";
				FRONT_position++;
			}
			cout << endl;
		}
	}
};

int main() {
	queues q;
	char ch;

	while (true) {
		try {
			cout << "Menu" << endl;
			cout << "1 inplemen insert operation" << endl;
			cout << "2 inplemen delete operation" << endl;
			cout << "3 display values" << endl;
			cout << "4 exit" << endl;
			cout << "enter your choise(1-4): ";
			cin >> ch;
			cout << endl;

			switch (ch) {
			case '1': {

				q.insert();
				break;
			}
			case '2': {
				q.remove();
				break;
			}
			case '3': {
				q.display();
				break;
			}
			case '4':
				return 0;
			}
			default: {
				cout << "invalid option" << endl;
				break;
			}
		}
		catch (exception& e) {
			cout << " Check for the values entered" << endl;
		}
            		    
	}
	return 0;
}
	

