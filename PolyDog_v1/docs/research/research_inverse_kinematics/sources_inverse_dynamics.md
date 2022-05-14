### Research about the inverse dynamics method

> **Definition :**
> Abstract. Manipulator inverse dynamics, or simply inverse dynamics, is the calculation of the forces and/or torques
> required at a robot's joints in order to produce a given motion trajectory consisting of a set of joint positions,
> velocities and accelerations.

> **Forward or inverse dynamics ?**
> 
> **This is an extract from the file inverse_vs_forward_dynamics**
> 
> The results of this work indicate that direct transcription
> implementations relying on forward dynamics to define the
> defect constraints can be reformulated with inverse dynamics
> to see an increase in performance, for both feasibility or minimization problems, and without sacrificing the feasibility
> of the solutions to the optimization problem. An additional
> reason to prefer inverse dynamics is robustness to coarser
> discretizations, both in terms of computation efficiency and
> faithfulness of solutions with respect to finer discretizations.
> When minimizing a cost function, the locally-optimal solutions computed with either formulation are essentially the
> same. However, when an objective function is not considered,
> the formulations may diverge to different solutions. Experimentally, we have observed that the solutions computed with
> inverse dynamics are easier to perform in real hardware. The
> reasons behind this divergence are not yet clear to us, and
> this is something we plan to investigate in future work.
> Erez and Todorov [13] observed a striking feature in their
> results: an emergent coordination between legs and opposite
> arms during a running gait. In this work, for the humanoid
> jumping task, we also observed such emerging behavior:
> the resulting motions swing the arms upwards to build-up
> energy before the take-off instant. Both in [13] and our work,
> these features originated without any explicit modeling—
> reaffirming the power of dynamic trajectory optimization.
> In recent work [28], we took into account uncertainty and
> robustness to disturbances using direct transcription. Considering uncertainty usually incurs additional computational
> cost due to more complex problem formulations. With the
> findings from this paper, we plan to redefine the dynamics
> defect constraints in that work with inverse dynamics, improving the performance of our robustness framework and
> making it more competitive.

### Conclusion
We should consider inverse dynamics as it is said to be more efficient and easier to implement in robotic projects.

# IDEAS AND SOURCES

**Coding train videos**

[Coding Challenge #64.1: Forward Kinematics](https://thecodingtrain.com/CodingChallenges/064.1-forward-kinematics.html)
[Coding Challenge #64.2: Inverse Kinematics](https://thecodingtrain.com/CodingChallenges/064.2-inverse-kinematics)
[Coding Challenge #64.3: Inverse Kinematics - Fixed Point](https://thecodingtrain.com/CodingChallenges/064.3-inverse-kinematics-fixed-point)
[Coding Challenge #64.4: Inverse Kinematics - Multiple](https://thecodingtrain.com/CodingChallenges/064.4-inverse-kinematics-multiple)

**Complete tutorial creating a four legged robot with arduino #KITtyBot**

[Tutorial link](https://create.arduino.cc/projecthub/StaffanEk/kittybot-f21cc0)

**Others**

[General description about inverse dynamics](http://www.clinicalgaitanalysis.com/teach-in/inverse-dynamics.html)
File : humanoid_modeling_inverse_control.pdf
File : history_models_legged_robotics.pdf
[Overview of inverse dynamics](https://medium.com/unity3danimation/overview-of-inverse-dynamics-2ed60d0c37ef)
[Equations inverse dynamics](https://hackaday.io/project/21757-object-following-control-of-a-robotic-camera-arm/log/61689-inverse-dynamics-controller)
[Wikipédia : modélisation de robots (très complet)](https://fr.wikipedia.org/wiki/Mod%C3%A9lisation_des_robots#Mod%C3%A9lisation_cin%C3%A9matique_inverse)
File : robot_humanoide_ds_corrige.pdf
