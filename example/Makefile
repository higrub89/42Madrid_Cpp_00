# --- Configuración del Chasis ---
NAME        = telemetria_final
LIB_NAME    = libmotor.a

# Compilador y Flags de alto rendimiento
CXX         = g++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98 -O3 -I.
AR          = ar rvs
RM          = rm -f

# --- Componentes (Archivos) ---
SRCS        = main.cpp
LIB_SRCS    = operaciones.cpp   
OBJS        = $(SRCS:.cpp=.o)
LIB_OBJS    = $(LIB_SRCS:.cpp=.o)

# --- Reglas de Construcción ---

# 1. Objetivo principal: El binario final
all: $(NAME)

$(NAME): $(OBJS) $(LIB_NAME)
	$(CXX) $(CXXFLAGS) $(OBJS) -L. -lmotor -o $(NAME)

# 2. Creación de la Biblioteca Estática (Objetoteca)
$(LIB_NAME): $(LIB_OBJS)
	$(AR) $(LIB_NAME) $(LIB_OBJS)

# 3. Regla implícita para compilar objetos (.cpp -> .o)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# --- Mantenimiento ---
clean:
	$(RM) $(OBJS) $(LIB_OBJS)

fclean: clean
	$(RM) $(NAME) $(LIB_NAME)

re: fclean all

.PHONY: all clean fclean re