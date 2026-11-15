#pragma once

#include "Wrapper.cpp"
#include <string>
#include <unordered_map>
#include <memory>
#include <iostream>


class Engine {
std::unordered_map<std::string, std::unique_ptr<BaseWrapper>> Wrappers;

public:
    void register_command(std::unique_ptr<BaseWrapper> w, std::string commandName) {
        Wrappers[commandName] = std::move(w);

        std::cout << "Успешно зарегистрирована команда под названием: " << commandName << std::endl;
    }

    std::any execute(std::string commandName, ArgDict arguments) {
        if (Wrappers.find(commandName) == Wrappers.end()) {
            throw std::runtime_error("Не найденно имя команды: " + commandName);
        }
        return Wrappers[commandName]->execute(arguments);
    }
};