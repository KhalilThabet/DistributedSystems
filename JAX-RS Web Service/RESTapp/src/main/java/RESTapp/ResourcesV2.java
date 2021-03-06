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

@Path("resourceV2")
public class ResourcesV2 {
	
	@GET
	public String hello() {
		return "Hello Client !";
	}
    private CustomerDataServiceV2 dataService2 = CustomerDataServiceV2.getInstance();

	
    @GET
    @Produces(MediaType.APPLICATION_JSON)
    public List<Customer> getCustomers() {
        return dataService2.getCustomerList();
    }


    @POST
    @Consumes({MediaType.APPLICATION_JSON})
    @Produces(MediaType.TEXT_PLAIN)
    public String createCustomer(Customer newCustomer) {
        dataService2.addCustomer(newCustomer);
        return "Welcome Client !";
    }

	@GET
    @Path("{id}")
    @Produces(MediaType.APPLICATION_JSON)
    public Customer getCustomer(@PathParam("id") String id) {
        return dataService2.getCustomerById(id);
    }
	
	
	
}
