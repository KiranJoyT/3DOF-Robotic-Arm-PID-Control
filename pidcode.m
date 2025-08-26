%% Creating slTuner and configuring it

TunedBlocks = {'PD1','PD2','PD3'};
STO = slTuner('dof3_RRR_pid',TunedBlocks);

% Mark outputs of PID blocks as plant inputs
addPoint(STO,TunedBlocks);

% Mark joint angles as plant outputs
addPoint(STO,'Robot/q1m');

% Mark reference signals
RefSignals = {...
'dof3_RRR_pid/Signal Builder1/q1n', 'dof3_RRR_pid/Signal Builder2/q2n', 'dof3_RRR_pid/Signal Builder3/q3n'};
addPoint(STO,RefSignals);

%% Defining Input and Outputs and Tuning the system
Controls = TunedBlocks; % actuator commands
Measurements = 'dof3_RRR_pid/Robot/q1m'; % joint angle measurements
options = looptuneOptions('RandomStart',80,'UseParallel',false); % For
TR = TuningGoal.StepTracking(RefSignals,Measurements,0.05,0);
ST1 = looptune(STO,Controls,Measurements,TR,options);

%% Update PID Block
writeBlockValue(ST1)
