#include "Packet.h"
using namespace std;

void disp(vector<string>& v) {
    for (int i = 0; i < v.size(); i++) cout << "[" << v[i] << "]";
    cout << endl;
}

string intToHex(int const& num) {
    // convert an integer to hexadecimal;
    stringstream ss;
    ss << hex << num;
    return ss.str();
}

unsigned int Packet::sequence_check = 0;

Packet::Packet(string const& message) : message(message) {
    // static variable to keep track of sequence number
    if (sequence_check < 7) sequence_check += 1;
    else sequence_check = 0;
    // split the message into fields and save them in an array;
    this->fields = this->split('|');
    // get the checksum from the last field and save it in a string;
    string last_field = fields[fields.size() - 1];
    this->message_checksum.push_back(last_field[last_field.size() - 2]);
    this->message_checksum.push_back(last_field[last_field.size() - 1]);
    // remove the checksum from the last field;
    this->fields[this->fields.size() - 1].pop_back();
    this->fields[this->fields.size() - 1].pop_back();
    // get the sequence number from the first field;
    this->message_sequence = this->fields[0][0] - '0';
    // remove the sequence number from the first field;
    this->fields[0].erase(this->fields[0].begin());
    // get the record type from the first field;
    this->record_type.push_back(this->fields[0][0]);
    // save the calculated checksum
    this->checksum_check = calculateChecksum();
    // if the packet isCorrupt we should decrement sequence check
    if (this->isCorrupt()) {
        sequence_check -= 1;
        checksum_check = "0";
    }
}
bool Packet::isCorrupt() const {
    // check if the Packet is corrupt;
    return message_checksum != checksum_check || message_sequence != sequence_check;
}
string Packet::getRecordType() const {
    return record_type;
}
vector<string> Packet::getData() const {
    // return the data fields;
    return fields;
}
void Packet::display() {
    // debug function to display the Packet;
    cout << message_sequence << " " << sequence_check << endl
        << message_checksum << " " << checksum_check << endl;
    disp(fields);
}

Packet::~Packet() {}

string Packet::data(string const& s) const {
    // return the data field of the Packet by removing <ETX>, <STX>, <CR>, <LF>.
    string res;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != 0x02 && s[i] != 0x03 && s[i] != 0x0D && s[i] != 0x0A)
            res += s[i];
    }
    return res;
}
string Packet::calculateChecksum() const {
    // calculate the checksum of the Packet;
    int sum = 16;
    // get the data field of the Packet;
    string data = this->data(message);
    data.pop_back(); data.pop_back();
    for (int i = 0; i < data.length(); i++) {
        int n = data[i];
        sum += n;
    }
    // get the ASCII value of the checksum % 256 (255 = FF which is the highest value for our 8-bit checksum);
    sum %= 256;
    // convert the checksum to a hexadecimal string;
    string res = intToHex(sum);
    // return the checksum using the hexadecimal string upper case;
    if (res[0] >= 'a' && res[0] <= 'f') res[0] -= 32;
    if (res[1] >= 'a' && res[1] <= 'f') res[1] -= 32;
    if (res.size() == 1) return "0" + res;
    return res;
}
vector<string> Packet::split(char const& separator) const {
    // split the data into fields;
    vector<string> result;
    stringstream ss(data(message));
    string item;
    // split the buffer into fields;
    while (getline(ss, item, separator)) result.push_back(item);
    // return the fields;
    return result;
}
