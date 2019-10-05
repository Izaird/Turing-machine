#include "turing.h"
#include "color.h"
void travel_r(int actual_state, int next_state, char tape_actual_char, Tape &tape, std::vector<State> &states);


int main(){
    std::vector<State> states;
    char event, tape_actual_char;
    int actual_state, next_state;
    bool run = true;

    states= createStates();
    std::cout << FGRN("Insert the tape: ") << std::endl;
    Tape tape(getString());

    actual_state = getInitialState(states);

    // do{
    //     tape_actual_char = tape.read();
    //     next_state = states[actual_state].getNextState(tape_actual_char);
    //     tape.update(states[actual_state].getNewEvent(tape_actual_char));
    //     tape.move(states[actual_state].getDirection(tape_actual_char));
    //     actual_state = next_state;
    //     if(states[actual_state].getAcceptance()){
    //         std::cout << "string accepted" << std::endl;
    //         run = false;
    //     }
    //     else if(actual_state == -1){
    //         std::cout << "string rejected" << std::endl;
    //         run = false;
    //     }
    // }while(run);

    travel_r(actual_state,next_state,tape_actual_char,tape,states);

    std::cout << "end" << std::endl;


    return 0;
}


    void travel_r(int actual_state, int next_state, char tape_actual_char, Tape &tape, std::vector<State> &states){
        if(states[actual_state].getAcceptance()){
            std::cout << "string accepted" << std::endl;
        }
        else if(actual_state == -1){
            std::cout << "string rejected" << std::endl;
        }
        else{
        tape_actual_char = tape.read();
        next_state = states[actual_state].getNextState(tape_actual_char);
        tape.update(states[actual_state].getNewEvent(tape_actual_char));
        tape.move(states[actual_state].getDirection(tape_actual_char));
        actual_state = next_state;
        travel_r(actual_state,next_state,tape_actual_char,tape,states);
        }
    }