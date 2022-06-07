#pragma once
#ifndef PACKET_H
#define PACKET_H
#define µ 49845

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

class Packet {
public:
    Packet(std::string const& message);
    bool isCorrupt() const;
    std::string getRecordType() const;
    std::vector<std::string> getData() const;
    void display(); // debug output remove later
    Packet() = delete;
    ~Packet();

private:
    std::string const& message;
    std::vector<std::string> fields;
    unsigned int message_sequence;
    static unsigned int sequence_check;
    std::string message_checksum;
    std::string checksum_check;
    std::string record_type;

    std::string data(std::string const&) const; // TODO edit later
    std::string calculateChecksum() const;
    std::vector<std::string> split(char const&) const;
};

#endif // !_PACKET_H
