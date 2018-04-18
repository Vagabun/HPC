#include "controllers/input_controller.h"
#include "helpers/output_wrapper.h"

int main() {

    /*input_controller g;
    g.start();*/

	output_wrapper &instance1 = output_wrapper::instance();

	output_wrapper &instance2 = output_wrapper::instance();

	//cout << instance1 << endl;

	output_wrapper::instance().print("hello");

    return 0;
}