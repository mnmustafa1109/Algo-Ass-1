#ifndef ALGO_ASS_1_PARSER_HXX
#define ALGO_ASS_1_PARSER_HXX

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "Passenger.hxx" // Assuming the Passenger class is defined in Passenger.h

class CSVParser
{
public:
    CSVParser(const std::string &filePath) : filePath(filePath) {}

    std::vector<Passenger> parseCSV()
{
    std::vector<Passenger> passengers;
    std::ifstream inputFile(filePath);

    if (!inputFile.is_open())
    {
        std::cerr << "Failed to open the file: " << filePath << std::endl;
        return passengers;
    }

    std::string line;
    bool firstLine = true; // To skip the header row

    while (std::getline(inputFile, line))
    {
        if (firstLine)
        {
            firstLine = false; // Skip the header row
            continue;
        }

        std::vector<std::string> tokens;

        size_t pos = 0;
        bool insideQuotes = false;
        std::string token;

        while (pos < line.length())
        {
            if (line[pos] == '"')
            {
                // Quoted field
                if (!insideQuotes)
                {
                    insideQuotes = true;
                }
                else
                {
                    insideQuotes = false;
                }
            }
            else if (line[pos] == ',' && !insideQuotes)
            {
                // Comma outside quotes, add the token
                tokens.push_back(token);
                token.clear();
            }
            else
            {
                token += line[pos];
            }
            pos++;
        }

        // Add the last token
        tokens.push_back(token);

        if (tokens.size() == 15)
        {
            // Process tokens and create Passenger object
            Passenger passenger(
                tokens[0], tokens[1], tokens[2], tokens[3], std::stoi(tokens[4]),
                tokens[5], tokens[6], tokens[7], tokens[8], tokens[9],
                tokens[10], tokens[11], tokens[12], tokens[13], tokens[14]);

            passengers.push_back(passenger);
        }
        else
        {
            std::cerr << "Invalid line: " << line << std::endl;
        }
    }

    inputFile.close();
    return passengers;
}


    void writeCSV(const std::string &filename, const std::vector<Passenger> &passengers)
    {
        std::ofstream outputFile(filename);

        if (!outputFile.is_open())
        {
            std::cerr << "Failed to open the file: " << filename << std::endl;
            return;
        }

        // Write the header row
        outputFile << "Passenger ID,First Name,Last Name,Gender,Age,Nationality,Airport Name,Airport Country Code,Country Name,Airport Continent,Continents,Departure Date,Arrival Airport,Pilot Name,Flight Status\n";

        // Write passenger data
        for (const Passenger &passenger : passengers)
        {
            outputFile << passenger.getId() << "," << passenger.getFirstName() << ","
                       << passenger.getLastName() << "," << passenger.getGender() << ","
                       << passenger.getAge() << "," << passenger.getNationality() << ","
                       << passenger.getAirportName() << "," << passenger.getAirportCountryCode() << ","
                       << passenger.getCountryName() << "," << passenger.getAirportContinent() << ","
                       << passenger.getContinents() << "," << passenger.getDepartureDate() << ","
                       << passenger.getArrivalAirport() << "," << passenger.getPilotName() << ","
                       << passenger.getFlightStatus() << "\n";
        }

        outputFile.close();
    }

private:
    std::string filePath;
};

#endif