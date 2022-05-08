package RESTapp;

import java.util.List;

import javax.ws.rs.Consumes;
import javax.ws.rs.GET;
import javax.ws.rs.POST;
import javax.ws.rs.Path;
import javax.ws.rs.PathParam;
import javax.ws.rs.Produces;
import javax.ws.rs.core.MediaType;

/**
 * 
 * @author Khalil Thabet
 *
 */
/*
 * {
    "name": "Khalil Thabet",
    "address": "Tunisia",
    "phoneNumber": "53256788",
    "email" : "khalil.thabet@ensi-uma.tn"
    }
 */

@Path("resource1")
public class ResourcesV1 {
	
	@GET
	public String hello() {
		return "Hello Client !";
	}
    private CustomerDataService dataService1 = CustomerDataService.getInstance();

	@GET
	@Path("{name}")
	public String Call(@PathParam("name") String name) {
		return "Welcome "+name;
	}
    @GET
    @Produces(MediaType.APPLICATION_JSON)
    public List<Customer> getCustomers() {
        return dataService1.getCustomerList();
    }


    @POST
    @Consumes(MediaType.APPLICATION_JSON)
    @Produces(MediaType.TEXT_PLAIN)
    public String createCustomer(Customer newCustomer) {
        dataService1.addCustomer(newCustomer);
        return "Welcome Client !";
    }

	@GET
    @Path("{id}")
    @Produces(MediaType.APPLICATION_JSON)
    public Customer getCustomer(@PathParam("id") String id) {
        return dataService1.getCustomerById(id);
    }
	
	
	
}
