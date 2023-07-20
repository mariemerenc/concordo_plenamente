cmake_minimum_required(VERSION 3.0)
project(Concordo VERSION 0.1 LANGUAGES CXX)

include_directories( include )

add_executable( program
                src/canal.cpp
                src/canalTexto.cpp
                src/canalVoz.cpp
                src/concordo.cpp
                src/exec.cpp
                src/mensagem.cpp
                src/servidor.cpp
                src/sistema.cpp
                src/usuario.cpp
                )

set_property(TARGET program PROPERTY CXX_STANDARD 11)