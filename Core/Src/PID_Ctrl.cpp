/*
 * PID_Ctrl.cpp
 *
 *  Created on: Apr 12, 2023
 *      Author: Ryu
 */
#include "PID_Ctrl.h"

namespace controll
{
	void controll::PID_Ctrl::transmit_PID()
	{
		if(isStop==false)
		{
			my_pwm.updata_PID(fb_stra, fb_turn);
		}
	}

	void controll::PID_Ctrl::get_enc_gyro()
	{
		omega_gyro=my_input.omega_gyro;
		v_encoder=my_input.v_encoder;
		if(now_cm.isTurn==true)
		{
			now_v=now_cm.gv;
			now_omega=my_kasoku.show_v();
		}
		else
		{
			now_v=my_kasoku.show_v();
			now_omega=0;
		}
	}

	void controll::PID_Ctrl::PID()
	{
		if(isStop==false)
		{
			get_enc_gyro();

			enc_error=now_v-v_encoder;
			enc_delta_error=enc_error-enc_old_error;
			enc_old_error=enc_error;
			enc_sigma_error+=enc_error;
			fb_stra=1/V_bat*(Ksp*enc_error+Ksi*enc_sigma_error*Ksd*enc_delta_error);

			gy_error=now_omega-omega_gyro;
			gy_delta_error=gy_error-gy_old_error;
			gy_old_error=gy_error;
			gy_sigma_error+=gy_error;
			fb_turn=1/V_bat*(Ktp*gy_error+Kti*gy_sigma_error*Ktd*gy_delta_error);

			transmit_PID();
		}
	}
}
