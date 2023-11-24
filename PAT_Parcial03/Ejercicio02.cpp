#include "Ejercicio02.h"
#include <unordered_map>

vector<string>* Ejercicio02::findRepeatedDnaSequences(Node<char>* head)
{
    std::unordered_map<string, int> sequencesMap;

    vector<string>* result = new vector<string>();

    string currentSequence;

    while (head != nullptr) {
        currentSequence.push_back(head->value);

        if (currentSequence.length() > 10) {
            currentSequence.erase(currentSequence.begin());
        }

        if (currentSequence.length() == 10) {
            sequencesMap[currentSequence]++;
        }

        head = head->next;
    }

    for (const auto& entry : sequencesMap) {
        if (entry.second > 1) {
            result->push_back(entry.first);
        }
    }

    return result;
}

