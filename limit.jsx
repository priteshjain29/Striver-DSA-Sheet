
//Pseudocode
{userRole === 'REVIEWER' || userRole === 'APPROVER' ? (
    <button onClick={checkLimitAvailability}>Check Limit Availability</button>
) : (
    <span>You do not have permission to check limit availability.</span>
)}



