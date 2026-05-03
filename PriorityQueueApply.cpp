#include <iostream>
#include <vector>
using namespace std;

struct Patient {
    string name;
    int age;
    string condition;
    int priority;
};

class HospitalQueue {
private:
    vector<Patient> heap;

    // Heapify Up
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;

            if (heap[index].priority > heap[parent].priority) {
                swap(heap[index], heap[parent]);
                index = parent;
            } else break;
        }
    }

    // Heapify Down
    void heapifyDown(int index) {
        int size = heap.size();

        while (index < size) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < size && heap[left].priority > heap[largest].priority)
                largest = left;

            if (right < size && heap[right].priority > heap[largest].priority)
                largest = right;

            if (largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            } else break;
        }
    }

public:
    // Register Patient
    void addPatient(string name, int age, string condition) {
        Patient p;
        p.name = name;
        p.age = age;
        p.condition = condition;

        if (condition == "Critical") p.priority = 3;
        else if (condition == "Serious") p.priority = 2;
        else p.priority = 1;

        heap.push_back(p);
        heapifyUp(heap.size() - 1);
    }

    // Treat Patient (remove highest priority)
    void treatPatient() {
        if (heap.empty()) {
            cout << "No patients in queue!\n";
            return;
        }

        Patient p = heap[0];
        cout << "\nTreating Patient:\n";
        cout << "Name: " << p.name << ", Age: " << p.age
             << ", Condition: " << p.condition << endl;

        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    // Show next patient
    void nextPatient() {
        if (heap.empty()) {
            cout << "No patients in queue!\n";
            return;
        }

        Patient p = heap[0];
        cout << "\nNext Patient:\n";
        cout << "Name: " << p.name << ", Condition: " << p.condition << endl;
    }

    // Display all patients
    void display() {
        cout << "\nCurrent Queue:\n";
        for (auto p : heap) {
            cout << p.name << " (" << p.condition << ") ";
        }
        cout << endl;
    }
};

int main() {
    HospitalQueue hq;

    hq.addPatient("Ali", 25, "Normal");
    hq.addPatient("Ahmed", 40, "Critical");
    hq.addPatient("Sara", 30, "Serious");
    hq.addPatient("Zain", 50, "Critical");

    hq.display();

    hq.nextPatient();

    hq.treatPatient();
    hq.display();

    return 0;
}